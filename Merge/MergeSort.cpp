#include "MergeSort.hh"

using namespace std;

template<class T>
void
MergeSort<T>::Merge(int min, int middle, int max)
{
	int i = min;
	int j = middle + 1;

	int minCount = (middle - min) + 1;
	int maxCount = (max - (middle + 1)) + 1;

	int minIter = 0;
	int maxIter = 0;

	cout << "Min: " << min << endl;
	cout << "Middle: " << middle << endl;
	cout << "Max: " << max << endl;
	cout << "Min Count: " << minCount << endl;
	cout << "Max Count: " << maxCount << endl;

	T *minArray = new T[minCount];
	T *maxArray = new T[maxCount];

	while (minIter < minCount)
		minArray[minIter++] = Common<T>::mArray[i++];

	while (maxIter < maxCount)
		maxArray[maxIter++] = Common<T>::mArray[j++];

	minIter = maxIter = 0;
	i = min;

	while (minIter < minCount && maxIter < maxCount)
		Common<T>::mArray[i++] = minArray[minIter] <= maxArray[maxIter] ?
			minArray[minIter++] : maxArray[maxIter++];

	while (minIter < minCount)
		Common<T>::mArray[i++] = minArray[minIter++];
	while (maxIter < maxCount)
		Common<T>::mArray[i++] = maxArray[maxIter++];

	delete [] minArray;
	delete [] maxArray;

}

template<class T>
void
MergeSort<T>::Sort()
{
	Sort(0, Common<T>::getLength());
	Common<T>::Print();
}

template<class T>
void
MergeSort<T>::Sort(int min, int max)
{
	if (min >= max)
		return;

	int middle = (min + max) / 2;

	Sort(min, middle);
	Sort(middle+1, max);
	Merge(min, middle, max);
}

int
main()
{
	MergeSort<int> *mergeSort = new MergeSort<int>("input.txt");
	mergeSort->Sort();
}

