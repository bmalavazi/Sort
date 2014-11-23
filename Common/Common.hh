#ifndef __COMMON__HH
#define __COMMON__HH


#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>


template <class T>
class Common
{
public:
	Common(const std::string &filename);
	~Common();

	virtual void Sort(int min, int max) = 0;
	virtual void Sort() = 0;
	
	void Swap(int a, int b);
	void Print();
	size_t getLength() { return mLength-1; }

protected:
	T *mArray;
	size_t mLength;
	std::fstream mFile;
};

#endif
