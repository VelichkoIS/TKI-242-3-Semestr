#pragma once
#include "Matrix.h"
#include "Generator.h"
/**
* @brief интерфейс выполнения заданий
*/
class Exercise
{
protected:
	Matrix<int>& array;
	Generator& gen;
public:
	/**
	* @brief конструктор
	* @param array массив
	* @param gen генератор
	*/
	Exercise(Matrix<int>& array, Generator& gen) : array{ array }, gen{ gen }
	{
	};
	/**
	* @brief чисто виртуальный метод выполнения первого задания
	*/
	virtual void Task1() = 0;
	/**
	* @brief чисто виртуальный метод выполнения первого задания
	*/
	virtual void Task2() = 0;
	/**
	* @brief чисто виртуальный деструктор
	*/
	virtual ~Exercise() = 0 {};
};

