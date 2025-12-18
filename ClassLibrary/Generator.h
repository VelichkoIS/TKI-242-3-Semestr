#pragma once
/**
* @brief интерфейс генератора чисел
*/
class Generator
{
public:
	/**
	* @brief чисто виртуальный метод заполнения массива
	*/
	virtual int generate() = 0;
	/**
	* @brief чисто виртуальный деструктор
	*/
	virtual ~Generator() = 0 {};
};

