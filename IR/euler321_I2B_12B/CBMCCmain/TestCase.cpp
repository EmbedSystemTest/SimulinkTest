#include "TestCase.h"
#include <assert.h>
#include <iostream>
#include <fstream>

TestCase::TestCase(int id, int sz, int bitmapSz, TestCase::BitmapType type)
{
	this->id = id;
	
	this->buffSize = sz;
	this->buff = new unsigned char[buffSize];
	
	this->bitmapLen = bitmapSz;
	
	switch (type) {
		case munit:
			this->munitBitmap = new unsigned char[bitmapLen];
			break;
		case branch:
			this->branchBitmap = new unsigned char[bitmapLen];
			break;
		case condition:
			this->condBitmap = new unsigned char[bitmapLen];
			break;
		case decision:
			this->decBitmap = new unsigned char[bitmapLen];
			break;
		case mcdc:
			this->mcdcBitmap = new std::vector<unsigned int>[bitmapLen];
			break;
		default:
			break;
	}
}

int TestCase::LoadFromFile(std::string file) const
{
	/*FILE * fp = fopen(file.c_str(), "r");

	// put the file pointer to the end of file. 
	fseek(fp, 0, SEEK_END);
	int filesize = ftell(fp); // get the number of fp pointer offsets by ftell fuction
	assert(buffSize == filesize);
	
	rewind(fp); // reset pointer to start;
	fread(this->buff, filesize, 1, fp);
	
	fclose(fp);
	return 1;*/
	std::ifstream infile(file.c_str(), std::ios::in | std::ios::binary);
	//get length of file
	infile.seekg(0, std::ios::end);
	size_t length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	// don't overflow the buffer!
	assert(length == buffSize);
	//read file
	infile.read((char*)buff, length);
	infile.close();
	return 1;
}

int TestCase::StoreToFile(std::string file) const
{
	/*FILE * fp = fopen(file.c_str(), "wb+");
	
	fwrite(this->buff, this->buffSize, 1, fp);
	fclose(fp);
	return 1;*/
	std::ofstream outfile(file.c_str(), std::ios::out | std::ios::binary);
	if (outfile) {
		outfile.write((char*)buff, buffSize);
		outfile.close();
	} else {
		return -1;
	}
	return 1;
}

/*void TestCase::ComputeInnerHashValue()
{
	this->mcdc_bitmapHash = ComputeHash(this->mcdc_bitmap, this->bitmapLen * sizeof(int));
}*/

void TestCase::Release() const
{
	delete buff;
}

TestCase::~TestCase()
{
	;
}

/*bool TestCase::operator < (const TestCase &b) const
{
	if (mcdc_bitmapHash < b.mcdc_bitmapHash) {
		return true;
	}
	else {
		if (mcdc_bitmapHash == b.mcdc_bitmapHash) {
			if (bitmapLen < b.bitmapLen) {
				return true;
			}
			else if (bitmapLen == b.bitmapLen) {
				for (int i = 0; i < bitmapLen; i++) {
					if (mcdc_bitmap[i] < b.mcdc_bitmap[i]) {
						return true;
					}
					else if (mcdc_bitmap[i] > b.mcdc_bitmap[i]) {
						return false;
					}
				}
				return false;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

bool TestCase::operator == (const TestCase &b) const
{
	if (mcdc_bitmapHash == b.mcdc_bitmapHash) {
		for (int i = 0; i < bitmapLen; i++) {
			if (mcdc_bitmap[i] != b.mcdc_bitmap[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

int ComputeHash(void* data, int dataLen) {
	unsigned char* dd = (unsigned char*) data;
	const int p = 16777619;
	const int h = 2166136261;
	const int h1 = 13;
	const int h2 = 7;
	const int h3 = 3;
	const int h4 = 17;
	const int h5 = 5;
	int hash = h;

	for (int i = 0; i < dataLen; i++)
		hash = (hash ^ dd[i]) * p;

	hash += hash << h1;
	hash ^= hash >> h2;
	hash += hash << h3;
	hash ^= hash >> h4;
	hash += hash << h5;
	return hash;
}*/


