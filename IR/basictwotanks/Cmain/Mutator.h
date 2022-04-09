#pragma once
#include <assert.h>

/*class Random :public std::minstd_rand {
public:
	Random(unsigned int seed) : std::minstd_rand(seed) {};
	result_type operator()() { return this->std::minstd_rand::operator()(); }
	size_t Rand() { return this->operator()(); }
	// get a random boolean
	size_t RandBoolean() { return Rand() % 2; }
	// get a random unsigned integer from 0 to n([0,n))	
	size_t operator()(size_t n) { return n ? Rand() % n : 0; }
	// get a random integer from x to y (y > x)
	intptr_t operator()(intptr_t from, intptr_t to) {
		assert(from < to);
		intptr_t range = to - from + 1;
		return operator()(from) + from;
	}
};*/

class Mutator {
public:
	// Random& rand
	Mutator() {
	};

	// random change a bit of data
//	void Mutate_ChangeBit(unsigned char* data, size_t size) {
//		assert(size > 0);
//		size_t index = rand(size);
//		data[index] ^= 1 << rand(8);
//	}

	// random change a byte of data
	void MutateChangeRandomPositionsByte(unsigned char* data, size_t size, int numPositions) const
	{
		assert(size > 0);
		for (int i = 0; i < numPositions; i++) {
			size_t index = rand() % size;
			data[index] = rand() % 256;
		}
	}

	// add one or subtract one for random byte 
//	void Mutate_SlightChangeByte(unsigned char* data, size_t size, byte change_num) {
//		assert(size > 0);
//		size_t index = rand() % size;
//		data[index] = (data[index] + change_num) % 256;
//	}

	// random change target bit 
//	void Mutate_ChangeBit(unsigned char* data, size_t size, size_t position) {
//		assert(position < size && size>0);
//		data[position] ^= 1 << rand() % 8;
//	}

	// random change target byte
	void MutateChangeByte(unsigned char* data, size_t size, size_t position) const
	{
		assert(position < size && size>0);
		data[position] = rand() % 256;
	}

	// add one or subtract one for target byte 
	void MutateSlightChangeByte(unsigned char* data, size_t size, size_t position, unsigned char changeNum) const
	{
		assert(position < size && size > 0);
		data[position] = (data[position] + changeNum) % 256;
	}

	unsigned char* GenerateSeed(size_t size) const
	{
		assert(size > 0);
		unsigned char* data = new unsigned char[size];
		for (int i = 0; i < size; i++) {
			data[i] = rand() % 256;
		}
		return data;
	}
	
	// Random &rand;
};