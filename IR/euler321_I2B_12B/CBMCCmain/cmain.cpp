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
const int buffLen = 200;
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
McdcBitmapResult processMCDCBitmap(int turns, std::vector<unsigned int>* bitmap, int bitmapLen, std::vector<unsigned int>* allBitmap, std::vector<unsigned int>* allBitmapTestCaseIndex, int currMcdcTestCaseIndex, unsigned int* allMcdcCov, unsigned char* mcdcMeta, int totalMcdcCov, int& allCov, std::string& allCovDetail, std::string extraInfo)
{
    McdcBitmapResult res = {false, false};
    bool newCov = false;
    allCovDetail = "";
    for (int i = 0; i < bitmapLen; i++) {
        std::vector<unsigned int> bitmapi = bitmap[i];
        assert(bitmapi.size() == 0 || bitmapi.size() >= 2);
        if (bitmapi.size() <= 1) {
            continue;
        }
        bitmapi.pop_back();
        std::sort(bitmapi.begin(), bitmapi.end());
        bitmapi.erase(std::unique(bitmapi.begin(), bitmapi.end()), bitmapi.end());
        std::vector<unsigned int> allBitmapI = allBitmap[i];
        std::vector<unsigned int> allBitmapTestCaseIndexI = allBitmapTestCaseIndex[i];
        for (std::vector<unsigned int>::iterator it = bitmapi.begin(); it != bitmapi.end(); it++) {
            unsigned int bits = *it;
            bool seen_before = false;
            std::vector<unsigned int>::iterator it2 = allBitmapI.begin();
            std::vector<unsigned int>::iterator idxIt2 = allBitmapTestCaseIndexI.begin();
            for (; it2 != allBitmapI.end() && idxIt2 != allBitmapTestCaseIndexI.end(); it2++, idxIt2++) {
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
                allBitmapI.push_back(bits);
                allBitmapTestCaseIndexI.push_back(currMcdcTestCaseIndex);
            }
            if (res.encRefineNew) {
                assert(res.encNew);
            }
        }
        allBitmap[i] = allBitmapI;
        allBitmapTestCaseIndex[i] = allBitmapTestCaseIndexI;
    }
    int inMunitCov = 0;
    std::cout << extraInfo << "_Bitmap: ";
    for (int k = 0; k < bitmapLen; k++) {
        int numO = CountOneInBinary(allMcdcCov[k]);
        allCovDetail += SPrintBinary(mcdcMeta[k], allMcdcCov[k]);
        inMunitCov += numO;
    }
    std::cout << allCovDetail;
    std::cout << std::endl;
    allCov = inMunitCov;
    printf("%d turn executed, %s: %d/%d;\n", turns, extraInfo.c_str(), inMunitCov, totalMcdcCov);
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
    if (isFileExist("./CoverageInfo/coverage_detail.json")) {
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
    struct tag_RTM_euler321_I2B_12B_T* euler321_I2B_12B_M = new struct tag_RTM_euler321_I2B_12B_T[1];
    euler321_I2B_12B_M[0].errorStatus = new char[1];
    euler321_I2B_12B_M[0].dwork = new struct DW_euler321_I2B_12B_T[1];
    double euler321_I2B_12B_U_phi[1];
    double euler321_I2B_12B_U_theta[1];
    double euler321_I2B_12B_U_psi[1];
    double euler321_I2B_12B_U_Vi[1][3];
    double euler321_I2B_12B_U_Inport[1];
    double euler321_I2B_12B_Y_DCM321[1][9];
    double euler321_I2B_12B_Y_Vb[1][3];
    double euler321_I2B_12B_Y_outTheta[1][3];
    double euler321_I2B_12B_Y_outGamma[1][3];
    unsigned char euler321_I2B_12B_Y_outR1[1];
    BitmapCov::munitBitmapLength = 2;
    BitmapCov::branchBitmapLength = 24;
    BitmapCov::condBitmapLength = 42;
    BitmapCov::decBitmapLength = 26;
    BitmapCov::mcdcBitmapLength = 13;
    mcdcMeta = new unsigned char[BitmapCov::mcdcBitmapLength] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, };
    int munitCov = 0;
    int branchCov = 0;
    int condCov = 0;
    int decCov = 0;
    int mcdcCov = 0;
    int totalMcdcCov = 0;
    for (int k = 0; k < BitmapCov::mcdcBitmapLength; k++) {
        totalMcdcCov += mcdcMeta[k];
    }
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
        // Add init buffer code
        for (int i = 0; i < 1; i++) {
            euler321_I2B_12B_init(&euler321_I2B_12B_M[i],euler321_I2B_12B_U_Vi[i],euler321_I2B_12B_Y_DCM321[i],euler321_I2B_12B_Y_Vb[i],euler321_I2B_12B_Y_outTheta[i],euler321_I2B_12B_Y_outGamma[i],&(euler321_I2B_12B_U_phi[i]),&(euler321_I2B_12B_U_theta[i]),&(euler321_I2B_12B_U_psi[i]),&(euler321_I2B_12B_U_Inport[i]),&(euler321_I2B_12B_Y_outR1[i]));
        }
        memcpy(&euler321_I2B_12B_U_phi[0], buffer + 0, 8);
        memcpy(&euler321_I2B_12B_U_theta[0], buffer + 8, 8);
        memcpy(&euler321_I2B_12B_U_psi[0], buffer + 16, 8);
        memcpy(&euler321_I2B_12B_U_Vi[0][0], buffer + 24, 8);
        memcpy(&euler321_I2B_12B_U_Vi[0][1], buffer + 32, 8);
        memcpy(&euler321_I2B_12B_U_Vi[0][2], buffer + 40, 8);
        memcpy(&euler321_I2B_12B_U_Inport[0], buffer + 48, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][0], buffer + 56, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][1], buffer + 64, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][2], buffer + 72, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][3], buffer + 80, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][4], buffer + 88, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][5], buffer + 96, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][6], buffer + 104, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][7], buffer + 112, 8);
        memcpy(&euler321_I2B_12B_Y_DCM321[0][8], buffer + 120, 8);
        memcpy(&euler321_I2B_12B_Y_Vb[0][0], buffer + 128, 8);
        memcpy(&euler321_I2B_12B_Y_Vb[0][1], buffer + 136, 8);
        memcpy(&euler321_I2B_12B_Y_Vb[0][2], buffer + 144, 8);
        memcpy(&euler321_I2B_12B_Y_outTheta[0][0], buffer + 152, 8);
        memcpy(&euler321_I2B_12B_Y_outTheta[0][1], buffer + 160, 8);
        memcpy(&euler321_I2B_12B_Y_outTheta[0][2], buffer + 168, 8);
        memcpy(&euler321_I2B_12B_Y_outGamma[0][0], buffer + 176, 8);
        memcpy(&euler321_I2B_12B_Y_outGamma[0][1], buffer + 184, 8);
        memcpy(&euler321_I2B_12B_Y_outGamma[0][2], buffer + 192, 8);
        // Add target function code
        for (int i = 0; i < 1; i++) {
            euler321_I2B_12B_step(&euler321_I2B_12B_M[0],euler321_I2B_12B_U_phi[i],euler321_I2B_12B_U_theta[i],euler321_I2B_12B_U_psi[i],euler321_I2B_12B_U_Vi[i],euler321_I2B_12B_U_Inport[i],euler321_I2B_12B_Y_DCM321[i],euler321_I2B_12B_Y_Vb[i],euler321_I2B_12B_Y_outTheta[i],euler321_I2B_12B_Y_outGamma[i],&(euler321_I2B_12B_Y_outR1[i]));
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
        McdcBitmapResult encNew5 = processMCDCBitmap(turns, BitmapCov::mcdcBitmap, BitmapCov::mcdcBitmapLength, mcdcAllBitmap, mcdcAllBitmapTestCaseIndex, mcdcCurrTid, allMcdcCov, mcdcMeta, totalMcdcCov, mcdcCov, mcdcCovDetail, "MCDCCoverage");
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
    if (mcdcCov >= totalMcdcCov || sRunTime >= iRunTime)
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
