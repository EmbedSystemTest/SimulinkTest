// Add define code
// Add head file code
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include "BitmapCov.h"
#include "define.h"
#include "Mutator.h"
#include "TestCase.h"
#include "Util.h"
#include <time.h>
#include <assert.h>
struct McdcBitmapResult {
    bool encNew;
    bool encRefineNew;
    std::set<unsigned int> encRefineOlds;
};
// Add declaration code
const int buffLen = 90;
// Add Function code
void GenerateSeed(Mutator& mutator, std::vector<TestCase*>& tcases, int buffLen, unsigned char* buffer)
{
    // generate seed
    unsigned char* buff;
    if (rand() % 3 < 2 && tcases.size() > 2) {
        int idx = rand() % tcases.size();
        std::vector<TestCase*>::const_iterator it(tcases.begin());
        // 'advance' the iterator random times
        advance(it, rand() % tcases.size());
        TestCase* tcase = *it;
        buff = new unsigned char[buffLen];
        memcpy(buff, tcase->buff, buffLen);
        mutator.MutateChangeRandomPositionsByte(buff, buffLen, rand() % buffLen);
    }
    else {
        buff = mutator.GenerateSeed(buffLen);
        memcpy(buffer, buff, buffLen);
    }
}
bool processBitmap(int turns, unsigned char* bitmap, int bitmapLen, unsigned char* allBitmap, int& allCov, std::string& allCovDetail, std::string extraInfo)
{
    allCovDetail = "";
    int in_munit_cov = 0;
    for (int k = 0; k < bitmapLen; k++) {
        allBitmap[k] = allBitmap[k] | bitmap[k];
    }
    std::cout << extraInfo << "_Bitmap: ";
    for (int k = 0; k < bitmapLen; k++) {
        if (allBitmap[k] > 0) {
            allCovDetail += "1";
            in_munit_cov++;
        }else {
            allCovDetail += "0";
        }
    }
    std::cout << allCovDetail;
    std::cout << std::endl;
    bool ret_true = false;
    if (allCov < in_munit_cov) {
        allCov = in_munit_cov;
        ret_true = true;
    }
    printf("%d turn executed, %s: %d/%d;\n", turns, extraInfo.c_str(), allCov, bitmapLen);
    if (ret_true) {
        return true;
    }
    return false;
}
int CountOneInBinary(unsigned int n)
{
    int count = 0;
    for (; n != 0; count++) {
        n = n & (n - 1);
    }
    return count;
}
std::string SPrintBinary(int digits, unsigned int data)
{
    std::string res = "";
    for (int i = 0; i < digits; i++) {
        unsigned int a = 1;
        a = a << i;
        unsigned int andRes = data & a;
        if (andRes == 0) {
            res = "0" + res;
        }
        else {
            res = "1" + res;
        }
    }
    return res;
}
std::string SPrintUIntArray(int bitmapLen, unsigned int* vect)
{
    std::string res = "";
    for (int i = 0; i < bitmapLen; i++)
    {
        unsigned int v = vect[i];
        res += std::to_string(v) + ";";
    }
    return res;
}
std::string SPrintUIntVectorArray(int bitmapLen, std::vector<unsigned int>* allBitmap)
{
    std::string res = "bitmapLen:" + std::to_string(bitmapLen)+"#";
    for (int i = 0; i < bitmapLen; i++) {
        res += std::to_string(i) + ":";
        std::vector<unsigned int> vect = allBitmap[i];
        for (std::vector<unsigned int>::iterator it = vect.begin(); it < vect.end(); it++)
        {
            unsigned int v = *it;
            res += std::to_string(v) + ";";
        }
    }
    res += "\n";
    return res;
}
McdcBitmapResult processMCDCBitmap(int turns, std::vector<unsigned int>* bitmap, int bitmapLen, std::vector<unsigned int>* allBitmap, std::vector<unsigned int>* allBitmapTestCaseIndex, int currMcdcTestCaseIndex, unsigned int* allMcdcCov, unsigned char* mcdcMeta, int& allCov, std::string& allCovDetail, std::string extraInfo)
{
    McdcBitmapResult res = {false, false};
    bool newCov = false;
    allCovDetail = "";
    for (int i = 0; i < bitmapLen; i++) {
        assert(bitmap[i].size() == 0 || bitmap[i].size() >= 2);
        if (bitmap[i].size() <= 1) {
            continue;
        }
        bitmap[i].pop_back();
        std::sort(bitmap[i].begin(), bitmap[i].end());
        bitmap[i].erase(std::unique(bitmap[i].begin(), bitmap[i].end()), bitmap[i].end());
        for (std::vector<unsigned int>::iterator it = bitmap[i].begin(); it != bitmap[i].end(); it++) {
            unsigned int bits = *it;
            bool seen_before = false;
            std::vector<unsigned int>::iterator it2 = allBitmap[i].begin();
            std::vector<unsigned int>::iterator idxIt2 = allBitmapTestCaseIndex[i].begin();
            for (; it2 != allBitmap[i].end() && idxIt2 != allBitmapTestCaseIndex[i].end(); it2++, idxIt2++) {
                unsigned int allBits = *it2;
                unsigned int allBitsIndex = *idxIt2;
                unsigned int iRes = bits ^ allBits;
                if (iRes == 0) {
                    seen_before = true;
                    break;
                }
                unsigned int decisionFlipped = iRes & 1;
                unsigned int conditionFlipped = iRes >> 1;
                unsigned int minusOne = conditionFlipped - 1;
                bool onlyOneConditionFlipped = ((conditionFlipped & minusOne) == 0);
                if (decisionFlipped && onlyOneConditionFlipped) {
                    int origin = allMcdcCov[i];
                    allMcdcCov[i] |= conditionFlipped;
                    if (origin != allMcdcCov[i]) {
                        res.encRefineNew = true;
                        res.encRefineOlds.insert(allBitsIndex);
                    }
                }
            }
            if (!seen_before) {
                res.encNew = true;
                allBitmap[i].push_back(bits);
                allBitmapTestCaseIndex[i].push_back(currMcdcTestCaseIndex);
            }
            if (res.encRefineNew) {
                assert(res.encNew);
            }
        }
    }
    int totalCov = 0;
    int inMunitCov = 0;
    std::cout << extraInfo << "_Bitmap: ";
    for (int k = 0; k < bitmapLen; k++) {
        totalCov += mcdcMeta[k];
        int numO = CountOneInBinary(allMcdcCov[k]);
        allCovDetail += SPrintBinary(mcdcMeta[k], allMcdcCov[k]);
        inMunitCov += numO;
    }
    std::cout << allCovDetail;
    std::cout << std::endl;
    printf("%d turn executed, %s: %d/%d;\n", turns, extraInfo.c_str(), inMunitCov, totalCov);
    /*std::string amsuiv = SPrintUIntArray(bitmapLen, allMcdcCov);
    printf("%d turn executed, allMcdcCov: %s;\n", turns, amsuiv.c_str());
    std::string bsuiv = SPrintUIntVector(bitmapLen, bitmap);
    printf("%d turn executed, bitmap: %s;\n", turns, bsuiv.c_str());
    std::string absuiv = SPrintUIntVector(bitmapLen, allBitmap);
    printf("%d turn executed, allBitmap: %s;\n", turns, absuiv.c_str());*/
    /*bool ret_true = false;
    if (allCov < in_munit_cov) {
        allCov = in_munit_cov;
        ret_true = true;
    }
    printf("%d turn executed, %s: %d/%d;\n", turns, extraInfo.c_str(), allCov, total_cov);
    assert(new_cov == ret_true);
    if (ret_true) {
        return true;
    }*/
    return res;
}
int main(int argc, char** argv)
{
    int iRunTime = 10;
    if (argc >= 2) {
        std::string runTime = std::string(argv[1]);
        iRunTime = atoi(runTime.c_str());
    }
    int iOnlyCov = 0;
    if (argc >= 3) {
        std::string onlyCov = std::string(argv[2]);
        iOnlyCov = atoi(onlyCov.c_str());
    }
    // int oriTestcaseId = -1;
    Mutator mutator;
    unsigned char buffer[buffLen];
    std::vector<TestCase*> oriTcases;
    std::vector<TestCase*> munitTcases;
    std::vector<TestCase*> branchTcases;
    std::vector<TestCase*> condTcases;
    std::vector<TestCase*> decTcases;
    std::vector<TestCase*> mcdcTcases;
    std::set<unsigned int> mcdcRefineTcaseIds;
    std::vector<std::string> tfiles;
    ListFiles("DatTestCases", tfiles);
    std::vector<std::string> cbmcFiles;
    ListFiles("CBMCDatTestCases", cbmcFiles);
    if (isFileExist("./DatTestCases/cov_detail.json")) {
        for (std::string tfile : tfiles) {
            if (stringStartsWith(tfile, "cond_")) {
                std::string filePath = "./DatTestCases/" + tfile;
                TestCase* tc = new TestCase(-1, buffLen, 0, TestCase::BitmapType::nocov);
                tc->LoadFromFile(filePath);
                oriTcases.push_back(tc);
            }
        }
    } else {
        for (std::string tfile : cbmcFiles) {
            std::string filePath = "./CBMCDatTestCases/" + tfile;
            // ori_testcase_id++;
            TestCase* tc = new TestCase(-1, buffLen, 0, TestCase::BitmapType::nocov);
            tc->LoadFromFile(filePath);
            oriTcases.push_back(tc);
        }
    }
    int oriTcP = 0;
    int oriTcSize = oriTcases.size();
    unsigned char* mcdcMeta = nullptr;
    int testcaseId = -1;
    // Add init code
    struct A1_state* self = new struct A1_state[10];
    unsigned char in1[10];
    int in2[10];
    int out1[10];
    int out2[10];
    BitmapCov::munitBitmapLength = 50;
    BitmapCov::branchBitmapLength = 16;
    BitmapCov::condBitmapLength = 16;
    BitmapCov::decBitmapLength = 16;
    BitmapCov::mcdcBitmapLength = 8;
    mcdcMeta = new unsigned char[BitmapCov::mcdcBitmapLength] { 1, 1, 1, 1, 1, 1, 1, 1, };
    int munitCov = 0;
    int branchCov = 0;
    int condCov = 0;
    int decCov = 0;
    int mcdcCov = 0;
    std::string munitCovDetail = "";
    std::string branchCovDetail = "";
    std::string condCovDetail = "";
    std::string decCovDetail = "";
    std::string mcdcCovDetail = "";
    unsigned char* munitAllBitmap = new unsigned char[BitmapCov::munitBitmapLength];
    memset(munitAllBitmap, 0, BitmapCov::munitBitmapLength * sizeof(unsigned char));
    unsigned char* branchAllBitmap = new unsigned char[BitmapCov::branchBitmapLength];
    memset(branchAllBitmap, 0, BitmapCov::branchBitmapLength * sizeof(unsigned char));
    unsigned char* condAllBitmap = new unsigned char[BitmapCov::condBitmapLength];
    memset(condAllBitmap, 0, BitmapCov::condBitmapLength * sizeof(unsigned char));
    unsigned char* decAllBitmap = new unsigned char[BitmapCov::decBitmapLength];
    memset(decAllBitmap, 0, BitmapCov::decBitmapLength * sizeof(unsigned char));
    std::vector<unsigned int>* mcdcAllBitmap = new std::vector<unsigned int>[BitmapCov::mcdcBitmapLength];
    std::vector<unsigned int>* mcdcAllBitmapTestCaseIndex = new std::vector<unsigned int>[BitmapCov::mcdcBitmapLength];
    unsigned int* allMcdcCov = new unsigned int[BitmapCov::mcdcBitmapLength];
    memset(allMcdcCov, 0, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
    bool shouldReturn = false;
    clock_t startTime = clock();
    int turns = -1;
    while (!shouldReturn)
    {
        turns++;
        if (oriTcP < oriTcSize) {
            TestCase* oTc = oriTcases[oriTcP];
            assert(buffLen == oTc->buffSize);
            memcpy(buffer, oTc->buff, oTc->buffSize);
            printf("%d turn existing current seed index to last: %d/%d;\n", turns, oriTcP, oriTcSize-1);
            oriTcP++;
        } else {
            if (iOnlyCov) {
                break;
            }
            GenerateSeed(mutator, branchTcases, buffLen, buffer);
        }
        BitmapCov::munitBitmap = new unsigned char[BitmapCov::munitBitmapLength];
        memset(BitmapCov::munitBitmap, 0, BitmapCov::munitBitmapLength * sizeof(unsigned char));
        BitmapCov::branchBitmap = new unsigned char[BitmapCov::branchBitmapLength];
        memset(BitmapCov::branchBitmap, 0, BitmapCov::branchBitmapLength * sizeof(unsigned char));
        BitmapCov::condBitmap = new unsigned char[BitmapCov::condBitmapLength];
        memset(BitmapCov::condBitmap, 0, BitmapCov::condBitmapLength * sizeof(unsigned char));
        BitmapCov::decBitmap = new unsigned char[BitmapCov::decBitmapLength];
        memset(BitmapCov::decBitmap, 0, BitmapCov::decBitmapLength * sizeof(unsigned char));
        assert(BitmapCov::mcdcBitmap == nullptr);
        BitmapCov::mcdcBitmap = new std::vector<unsigned int>[BitmapCov::mcdcBitmapLength];
        // memset(BitmapCov::mcdcBitmap, 0, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
        // Add init buffer code
        for (int i = 0; i < 10; i++) {
            A1_Init(&self[i]);
        }
        memcpy(&self[0].Ramp_lastValue, buffer + 0, 4);
        memcpy(&self[1].Ramp_lastValue, buffer + 4, 4);
        memcpy(&self[2].Ramp_lastValue, buffer + 8, 4);
        memcpy(&self[3].Ramp_lastValue, buffer + 12, 4);
        memcpy(&self[4].Ramp_lastValue, buffer + 16, 4);
        memcpy(&self[5].Ramp_lastValue, buffer + 20, 4);
        memcpy(&self[6].Ramp_lastValue, buffer + 24, 4);
        memcpy(&self[7].Ramp_lastValue, buffer + 28, 4);
        memcpy(&self[8].Ramp_lastValue, buffer + 32, 4);
        memcpy(&self[9].Ramp_lastValue, buffer + 36, 4);
        memcpy(&in1[0], buffer + 40, 1);
        memcpy(&in1[1], buffer + 41, 1);
        memcpy(&in1[2], buffer + 42, 1);
        memcpy(&in1[3], buffer + 43, 1);
        memcpy(&in1[4], buffer + 44, 1);
        memcpy(&in1[5], buffer + 45, 1);
        memcpy(&in1[6], buffer + 46, 1);
        memcpy(&in1[7], buffer + 47, 1);
        memcpy(&in1[8], buffer + 48, 1);
        memcpy(&in1[9], buffer + 49, 1);
        memcpy(&in2[0], buffer + 50, 4);
        memcpy(&in2[1], buffer + 54, 4);
        memcpy(&in2[2], buffer + 58, 4);
        memcpy(&in2[3], buffer + 62, 4);
        memcpy(&in2[4], buffer + 66, 4);
        memcpy(&in2[5], buffer + 70, 4);
        memcpy(&in2[6], buffer + 74, 4);
        memcpy(&in2[7], buffer + 78, 4);
        memcpy(&in2[8], buffer + 82, 4);
        memcpy(&in2[9], buffer + 86, 4);
        // Add target function code
        for (int i = 0; i < 10; i++) {
            A1_Update(&self[i],in1[i],in2[i],&(out1[i]),&(out2[i]));
        }
        // testcase_id++;
        bool enc_new1 = processBitmap(turns, BitmapCov::munitBitmap, BitmapCov::munitBitmapLength, munitAllBitmap, munitCov, munitCovDetail, "ModelUnitCoverage");
        if (enc_new1) {
            TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::munitBitmapLength, TestCase::BitmapType::munit);
            //	memcpy(buffer, tc->buff, tc->buffSize);
            memcpy(tc->buff, buffer, buffLen);
            memcpy(tc->munitBitmap, BitmapCov::munitBitmap, BitmapCov::munitBitmapLength);
            munitTcases.push_back(tc);
        }
        memset(BitmapCov::munitBitmap, 0, BitmapCov::munitBitmapLength);
        bool enc_new2 = processBitmap(turns, BitmapCov::branchBitmap, BitmapCov::branchBitmapLength, branchAllBitmap, branchCov, branchCovDetail, "BranchCoverage");
        if (enc_new2) {
            TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::branchBitmapLength, TestCase::BitmapType::branch);
            //	memcpy(buffer, tc->buff, tc->buffSize);
            memcpy(tc->buff, buffer, buffLen);
            memcpy(tc->branchBitmap, BitmapCov::branchBitmap, BitmapCov::branchBitmapLength);
            branchTcases.push_back(tc);
        }
        memset(BitmapCov::branchBitmap, 0, BitmapCov::branchBitmapLength);
        bool enc_new3 = processBitmap(turns, BitmapCov::condBitmap, BitmapCov::condBitmapLength, condAllBitmap, condCov, condCovDetail, "ConditionCoverage");
        if (enc_new3) {
            TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::condBitmapLength, TestCase::BitmapType::condition);
            //	memcpy(buffer, tc->buff, tc->buffSize);
            memcpy(tc->buff, buffer, buffLen);
            memcpy(tc->condBitmap, BitmapCov::condBitmap, BitmapCov::condBitmapLength);
            condTcases.push_back(tc);
        }
        memset(BitmapCov::condBitmap, 0, BitmapCov::condBitmapLength);
        bool enc_new4 = processBitmap(turns, BitmapCov::decBitmap, BitmapCov::decBitmapLength, decAllBitmap, decCov, decCovDetail, "DecisionCoverage");
        if (enc_new4) {
            TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::decBitmapLength, TestCase::BitmapType::decision);
            //	memcpy(buffer, tc->buff, tc->buffSize);
            memcpy(tc->buff, buffer, buffLen);
            memcpy(tc->decBitmap, BitmapCov::decBitmap, BitmapCov::decBitmapLength);
            decTcases.push_back(tc);
        }
        memset(BitmapCov::decBitmap, 0, BitmapCov::decBitmapLength);
        int mcdcCurrTid = mcdcTcases.size();
        McdcBitmapResult encNew5 = processMCDCBitmap(turns, BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength, mcdcAllBitmap, mcdcAllBitmapTestCaseIndex, mcdcCurrTid, allMcdcCov, mcdcMeta, mcdcCov, mcdcCovDetail, "MCDCCoverage");
        if (encNew5.encNew) {
            TestCase* tc = new TestCase(testcaseId, buffLen, BitmapCov::mcdcBitmapLength, TestCase::BitmapType::mcdc);
            // memcpy(buffer, tc->buff, tc->buffSize);
            memcpy(tc->buff, buffer, buffLen);
            for (int i = 0; i < BitmapCov::mcdcBitmapLength; i++) {
                tc->mcdcBitmap[i].assign(BitmapCov::mcdcBitmap[i].begin(), BitmapCov::mcdcBitmap[i].end());
            }
            //	memcpy(tc->mcdc_bitmap, BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
            mcdcTcases.push_back(tc);
            assert(mcdcCurrTid == mcdcTcases.size() - 1);
            if (encNew5.encRefineNew) {
                mcdcRefineTcaseIds.insert(mcdcCurrTid);
                mcdcRefineTcaseIds.insert(encNew5.encRefineOlds.begin(), encNew5.encRefineOlds.end());
            }
        }
        delete[] BitmapCov::mcdcBitmap;
        BitmapCov::mcdcBitmap = nullptr;
        // }
    // memset(BitmapCov::mcdcBitmap, 0, BitmapCov::mcdcBitmapLength * sizeof(unsigned int));
    clock_t endTime = clock();
    double sRunTime = (endTime - startTime) / CLOCKS_PER_SEC;
    if (branchCov >= BitmapCov::branchBitmapLength || sRunTime >= iRunTime)
    {
        shouldReturn = true;
    }
}
// Add code after execute
int munitIdx = 0;
for (TestCase* mtc : munitTcases) {
    std::string filePath = "./DatTestCases/munit_" + std::to_string(munitIdx) + ".dat";
    mtc->StoreToFile(filePath);
    munitIdx++;
}
int branchIdx = 0;
for (TestCase* btc : branchTcases) {
    std::string filePath = "./DatTestCases/branch_" + std::to_string(branchIdx) + ".dat";
    btc->StoreToFile(filePath);
    branchIdx++;
}
int condIdx = 0;
for (TestCase* ctc : condTcases) {
    std::string filePath = "./DatTestCases/cond_" + std::to_string(condIdx) + ".dat";
    ctc->StoreToFile(filePath);
    condIdx++;
}
int decIdx = 0;
for (TestCase* ctc : decTcases) {
    std::string filePath = "./DatTestCases/dec_" + std::to_string(decIdx) + ".dat";
    ctc->StoreToFile(filePath);
    decIdx++;
}
int mcdcRefineIdx = 0;
for (unsigned int mrtcIdx : mcdcRefineTcaseIds) {
    std::string filePath = "./DatTestCases/mcdc_refine_" + std::to_string(mcdcRefineIdx) + ".dat";
    TestCase* mrtc = mcdcTcases[mrtcIdx];
    mrtc->StoreToFile(filePath);
    mcdcRefineIdx++;
}
std::string finalCovDetail = "";
finalCovDetail += "{";
    finalCovDetail += "\"model unit coverage\":\"" + munitCovDetail + "\",";
    finalCovDetail += "\"branch coverage\":\"" + branchCovDetail + "\",";
    finalCovDetail += "\"condition coverage\":\"" + condCovDetail + "\",";
    finalCovDetail += "\"decision coverage\":\"" + decCovDetail + "\",";
    finalCovDetail += "\"mcdc coverage\":\"" + mcdcCovDetail + "\"";
    finalCovDetail += "}";
FileWrite("./CoverageInfo/coverage_detail.json", finalCovDetail);
// Add release code
return 0;
}
