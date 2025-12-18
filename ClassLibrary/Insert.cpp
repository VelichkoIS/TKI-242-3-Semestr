#include "Insert.h"

Insert::Insert(Matrix<int>& array, Generator& gen) : Exercise{array,gen}
{
}

void Insert::showArray()
{
	for (size_t i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Insert::Task1()
{
}

void Insert::Task2()
{
	for (size_t i = 0; i < array.getSize(); i++)
	{
			int j = abs(array[i]) % 10;
			{
				elementInsertion(i + 1, j);
				elementInsertion(i, j);
				i += 2;
			}
	}
}

void Insert::elementInsertion(const size_t index, const int value)
{
	size_t oldSize = array.getSize();
	size_t cIndex = (index > oldSize) ? oldSize : index;

	shared_ptr<int[]> newArr(new int[oldSize + 1]);

	for (size_t i = 0, j = 0; i < oldSize + 1; i++, j++)
	{
		if (i == cIndex && i == oldSize) 
		{
			newArr[i] = value;
			break;
		}
		else if (i == cIndex) 
		{
			newArr[i] = value;
			i++; 
		}
		if (j < oldSize)
		{
			newArr[i] = array[j];
		}
	}
	array.setSize(oldSize + 1);
	array.setFirstPtr(newArr);
}