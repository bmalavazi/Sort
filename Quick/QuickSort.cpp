#include "QuickSort.hh"

using namespace std;

//template<class T>
//QuickSort<T>::QuickSort(const std::string &filename)
//{
	//Common<T>::Common(filename);
//}

template<class T>
int
QuickSort<T>::Partition(int min, int max)
{
	int i = min - 1;
	int partition = Common<T>::mArray[max];

	for (int j = min; j <= max - 1; j++) {
		if (Common<T>::mArray[j] < partition) {
			i++;
			Common<T>::Swap(i, j);
		}
	}

	Common<T>::Swap(i+1, max);
	return i+1;
}

template<class T>
void
QuickSort<T>::Sort(int min, int max)
{
	if (min < max) {
		int partition = Partition(min, max);
		Sort(min, partition-1);
		Sort(partition+1, max);
	}
}

template<class T>
void
QuickSort<T>::Sort()
{
	Sort(0, Common<T>::mLength-1);
	Common<T>::Print();
}

int
main()
{
	QuickSort<int> *Quick = new QuickSort<int>("input.txt");

	Quick->Sort();

	return 0;
}
