#pragma once
#include <string>
#include <vector>

class TestCase {
public:
	int id = -1;

	unsigned char* buff = nullptr;
	int buffSize = -1;

	unsigned char* munitBitmap = nullptr;

	unsigned char* branchBitmap = nullptr;

	unsigned char* condBitmap = nullptr;

	unsigned char* decBitmap = nullptr;

	std::vector<unsigned int>* mcdcBitmap = nullptr;

//	int mcdcBitmapHash = -1;

	int bitmapLen = -1;
	
	enum BitmapType {
		munit,
		branch,
		condition,
		decision,
		mcdc,
		nocov,
	};
	
	explicit TestCase(int id, int sz, int bitmapSz, BitmapType type);
	int LoadFromFile(std::string file) const;
	int StoreToFile(std::string file) const;
//	void ComputeInnerHashValue();
	void Release() const;
	~TestCase();
	
//	bool operator < (const TestCase &b) const;
//	bool operator == (const TestCase &b) const;
	
private:
};

// int ComputeHash(void* data, int dataLen);



