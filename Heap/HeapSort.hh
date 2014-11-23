#ifndef __HEAPSORT__H
#define __HEAPSORT__H

#include "../Common/Common.cpp"

template<class T>
class HeapSort : public Common<T>
{
public:
	HeapSort(const std::string &filename) : Common<T>(filename), mHeapSize(0) {}
	void Sort();
	void Sort(int min, int max) {}
	int getLeftChild(int idx) { return 2*idx + 1; }
	int getRightChild(int idx) { return 2*idx + 2; }
	void MaxHeapify(int idx);
	void BuildMaxHeap();

private:
	size_t mHeapSize;
};

#endif
