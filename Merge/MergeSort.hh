#ifndef __MERGESORT__HH
#define __MERGESORT__HH

#include "../Common/Common.cpp"

template<class T>
class MergeSort : public Common<T>
{
public:
	MergeSort(const std::string &filename) : Common<T>(filename) {}
	void Sort(int min, int max);
	void Sort();
	void Merge(int min, int middle, int max);
};

#endif
