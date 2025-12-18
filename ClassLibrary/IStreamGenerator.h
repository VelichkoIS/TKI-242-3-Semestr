#pragma once
#include "Generator.h"
#include <iostream>

/**
* @brief генератор чисел читающий числа из потока ввода
*/
class IStreamGenerator : public Generator
{
private:
	std::istream& in;
public:
	/**
	* @brief конструктор
	* @param in поток ввода
	*/
	IStreamGenerator(std::istream& in = std::cin);
	/**
	* @brief возвращает значение введенное в потоке ввода
	*/
	int generate() override;
};


