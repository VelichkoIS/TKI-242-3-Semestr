#pragma once
#include "Generator.h"
#include <random>
/**
* @brief генератор для заполнения массива случайными числами
*/
class RandomGenerator :
    public Generator
{
private:
	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;
public:
	/**
	* @brief конструктор
	* @param min минимальное доступное значение
	* @param max максимально доступное значение
	*/
	RandomGenerator(const int min, const int max);
	/**
	* @brief возвращает сгенерированые значения
	*/
	int generate() override;
};

