#ifndef __QUICKSORT__HH
#define __QUICKSORT__HH

#include "../Common/Common.cpp"

template<class T>
class QuickSort : public Common<T>
{
public:
	QuickSort(const std::string &filename) : Common<T>(filename) {}
	void Sort(int min, int max);
	void Sort();

	int Partition(int min, int max);
};

#endif
