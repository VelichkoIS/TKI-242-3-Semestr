#pragma once
#include "Medicine.h"
#include <ctime>
	/**
	* @brief 1 продажа
	*/
class Sale
{
private:
	Medicine medicine;
	std::time_t timeOfSale;
	std::string name = medicine.getName();
public:
	/**
	* @brief конструктор
	* @param item лекарство
	*/
	Sale(Medicine item);
	/**
	* @brief метод возвращает название проданного лекарства
	*/
	std::string getName();
	/**
	* @brief метод подтверждает или опровергает была ли совершена покупка неделю назад
	*/
	bool isWithinLastWeek() const;
	/**
	* @brief метод подтверждает или опровергает была ли совершена покупка месяц назад
	*/
	bool isWithinLastMounth() const;
	/**
	* @brief метод подтверждает или опровергает была ли совершена покупка год назад
	*/
	bool isWithinLastYear() const;
};

