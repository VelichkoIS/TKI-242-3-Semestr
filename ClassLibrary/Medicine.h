#pragma once
#include <string>
	/**
	* @brief метод возвращает название лекарства
	*/
class Medicine
{
private:
	std::string name;
	std::string formOfIssue;
	std::string expirationDate;
	std::string annotation;
	double price;
	std::string manufacturer;
	std::string illness;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Medicine();
	/**
	* @brief конструктор
	* @param name название лекарства
	* @param formOfIssue форма выпуска
	* @param expirationDate срок годности
	* @param annotation аннотация
	* @param price цена
	* @param manufacturer производитель
	* @param illness болезнь
	*/
	Medicine(const std::string& name, const std::string& formOfIssue, const std::string& expirationDate,
		const std::string& annotation, const double& price, const std::string& manufacturer, const std::string& illness);
	/**
	* @brief метод возвращает название
	*/
	std::string getName();
	/**
	* @brief метод возвращает форму выпуска
	*/
	std::string getFormOfIssue();
	/**
	* @brief метод возвращает дату истечения срока годности
	*/
	std::string getExpirationDate();
	/**
	* @brief метод возвращает аннотацию 
	*/
	std::string getAnnotation();
	/**
	* @brief метод возвращает цену
	*/
	double getPrice();
	/**
	* @brief метод возвращает производителя
	*/
	std::string getManufacturer();
	/**
	* @brief метод возвращает название болезни
	*/
	std::string getIllness();
	friend bool operator==(Medicine item1, Medicine item2);
};

