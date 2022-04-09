#pragma once
#include <vector>
#include <map>

class BitmapCov {
public:
	static unsigned char* munitBitmap;
	static int munitBitmapLength;
	
	static unsigned char* branchBitmap;
	static int branchBitmapLength;
	
	static unsigned char* condBitmap;
	static int condBitmapLength;
	
	static unsigned char* decBitmap;
	static int decBitmapLength;

	static std::vector<unsigned int>* mcdcBitmap;
	static int mcdcBitmapLength;

	static bool CondRecord(bool res, int condIdx);
	static bool CondAndMCDCRecord(bool res, int condIdx, int decCondIdx, int decIdx);

};


