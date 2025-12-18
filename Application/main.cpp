#include <iostream>
#include "../ClassLibrary/Matrix.h"
#include "../ClassLibrary/RandomGenerator.h"
#include "../ClassLibrary/IStreamGenerator.h"
#include "../ClassLibrary/FWZeroes.h"
#include "../ClassLibrary/FWConst.h"
#include "../ClassLibrary/Swap.h"
#include "../ClassLibrary/Insert.h"

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Выберите способ заполнения массива:" << endl;
	cout << "1 - генератор случайных чисел" << endl;
	cout << "2 - ввод чисел вручную" << endl;
	cout << "3 - заполнение 0" << endl;
	cout << "4 - заполнение константным значением" << endl;
	int choice = 0;
	cin >> choice;
	cout << "Введите размер массива: " << endl;
	size_t size;
	cin >> size;
	Matrix<int> array(size);
	Generator* gen = new RandomGenerator(-10, 10);
	switch (choice)
	{
	case 1:
	{
		gen = new RandomGenerator(-10,10);
		break;
	}
	case 2:
	{
		gen = new IStreamGenerator(cin);
		break;
	}
	case 3:
	{
		gen = new FWZeroes;
		break;
	}
	case 4:
	{
		cout << "Введите одно значение которым будет заполнен весь массив" << endl;
		int value;
		cin >> value;
		gen = new FWConst(value);
		break;
	}
	default:
		cout << "Введено неверное значение, числа будут сгенерированы случайным образом на интервале от -10 до 10" << endl;
	}
	Swap exercise1(array, *gen);
	exercise1.showArray();
	exercise1.Task1();
	cout << "Поменяли местами последний и наибольший по модулю элементы" << endl;
	exercise1.showArray();
	Insert exercise2(array, *gen);
	exercise2.Task2();
	cout << "Добавили по одному элементу K спереди и сздади элемента оканчивающегося на цифру K" << endl;
	exercise2.showArray();
	delete gen;
	
	return 0;
}
