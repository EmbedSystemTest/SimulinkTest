#include "BitmapCov.h"
#include <vector>

unsigned char* BitmapCov::munitBitmap = nullptr;
int BitmapCov::munitBitmapLength = 0;

unsigned char* BitmapCov::branchBitmap = nullptr;
int BitmapCov::branchBitmapLength = 0;

unsigned char* BitmapCov::condBitmap = nullptr;
int BitmapCov::condBitmapLength = 0;

unsigned char* BitmapCov::decBitmap = nullptr;
int BitmapCov::decBitmapLength = 0;

std::vector<unsigned int>* BitmapCov::mcdcBitmap = nullptr;
int BitmapCov::mcdcBitmapLength = 0;

bool BitmapCov::CondRecord(bool res, int condIdx)
{
	if (condIdx >= 0) {
		// handle condition
		if (res) {
			BitmapCov::condBitmap[condIdx] = 1;
		}
		else {
			BitmapCov::condBitmap[condIdx+1] = 1;
		}
	}
	else {
		// handle decision
		if (res) {
			// for decision id, it is set to decid+1 when parameter incoming. 
			// thus, here need to -1. 
			BitmapCov::decBitmap[(-condIdx-1)] = 1;
		}
		else {
			BitmapCov::decBitmap[(-condIdx-1)+1] = 1;
		}
	}
	return res;
}

bool BitmapCov::CondAndMCDCRecord(bool res, int condIdx, int decCondIdx, int decIdx)
{
	BitmapCov::CondRecord(res, condIdx);

	// handle mcdc
	std::vector<unsigned int> vect = BitmapCov::mcdcBitmap[decIdx];
	if (vect.size() == 0) {
		vect.push_back(0);
	}
	int lastPos = vect.size() - 1;
	vect[lastPos] |= ((res ? 1 : 0) << decCondIdx);
	if (decCondIdx == 0) {
		vect.push_back(0);
	}
	BitmapCov::mcdcBitmap[decIdx] = vect;
	return res;
}

