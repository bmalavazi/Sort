#include "Common.hh"

using namespace std;

template<class T>
Common<T>::Common(const std::string &filename)
{
	T value;
	int i = 0;

	mArray = NULL;
	mLength = 0;

	mFile.open(filename);

	mLength = count(istreambuf_iterator<char>(mFile),
					istreambuf_iterator<char>(),
					'\n');

	mFile.clear();
	mFile.seekg(0, ios::beg);

	cout << "Length is: " << mLength << endl;

	mArray = new T[mLength];

	while (mFile >> value)
		mArray[i++] = value;
}

template<class T>
void
Common<T>::Swap(int a, int b)
{
	T tmp = mArray[a];
	mArray[a] = mArray[b];
	mArray[b] = tmp;
}

template<class T>
void
Common<T>::Print()
{
	for (int i = 0; i < mLength; i++)
		cout << mArray[i] << endl;
}

template<class T>
Common<T>::~Common()
{
	delete [] mArray;
	mFile.close();
}
