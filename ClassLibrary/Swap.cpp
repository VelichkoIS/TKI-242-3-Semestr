#include "Swap.h"

Swap::Swap(Matrix<int>& array, Generator& gen) : Exercise(array,gen)
{
	for (size_t i = 0; i < array.getSize(); i++)
	{
		array[i] = gen.generate();
	}
}

void Swap::showArray()
{
	for (size_t i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

size_t Swap::findMaxM()
{
	size_t index = 0;
	for (size_t i = 1; i < array.getSize(); i++)
	{
		if (abs(array[index]) < abs(array[i]))
		{
			index = i;
		}
	}
	return index;
}

void Swap::swap_two_elements(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void Swap::Task1()
{
	size_t index = findMaxM();
	swap_two_elements(array[index], array[array.getSize() - 1]);
}

void Swap::Task2()
{
}