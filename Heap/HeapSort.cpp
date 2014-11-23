#include "HeapSort.hh"

template<class T>
void
HeapSort<T>::MaxHeapify(int idx)
{
	int largest;
	int left = getLeftChild(idx);
	int right = getRightChild(idx);


	if (left < mHeapSize &&
		Common<T>::mArray[left] > Common<T>::mArray[idx]) {
		largest = left;
	} else {
		largest = idx;
	}

	if (right < mHeapSize &&
		Common<T>::mArray[right] > Common<T>::mArray[largest]) {
		largest = right;
	}

	if (largest != idx) {
		Common<T>::Swap(idx, largest);
		MaxHeapify(largest);
	}
}

template<class T>
void
HeapSort<T>::BuildMaxHeap()
{
	mHeapSize = Common<T>::mLength;

	for (int i = Common<T>::mLength/2; i >= 0; i--) {
		MaxHeapify(i);
	}
}

template<class T>
void
HeapSort<T>::Sort()
{
	BuildMaxHeap();

	for (int i = Common<T>::getLength(); i >= 1; i--) {
		Common<T>::Swap(0, i);
		mHeapSize--;
		MaxHeapify(0);
	}

	Common<T>::Print();
}

int
main()
{
	HeapSort<int> *heapSort = new HeapSort<int>("input.txt");
	heapSort->Sort();
}
