#include "InquiryOffice.h"
#include <iostream>

InquiryOffice::InquiryOffice() : inStock{}, sales {}
{
}

InquiryOffice::InquiryOffice(std::vector<Medicine> inStock) : inStock{inStock}
{

}

void InquiryOffice::addToStock(Medicine item)
{
	inStock.push_back(item);
}

void InquiryOffice::showInformation(std::string name)
{
	for (size_t i = 0; i < inStock.size(); i++)
	{
		if (inStock[i].getName() == name)
		{
			std::cout << "Информация о препарате " << inStock[i].getName() << std::endl;
			std::cout << "Форма выпуска: " << inStock[i].getFormOfIssue() << std::endl;
			std::cout << "Аннотация: " << inStock[i].getAnnotation() << std::endl;
			std::cout << "Срок годности: " << inStock[i].getExpirationDate() << std::endl;
			std::cout << "Производитель: " << inStock[i].getManufacturer() << std::endl;
		}
	}
}

void InquiryOffice::showMedicine(std::string illness)
{
	int counter = 0;
	for (size_t i = 0; i < inStock.size(); i++)
	{
		if (inStock[i].getIllness() == illness)
		{
			std::cout << inStock[i].getName() << ", ";
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Лекарств от данной болезни нету в наличии" << std::endl;
	}
}

Medicine InquiryOffice::findByName(std::string name)
{
	for (size_t i = 0; i < inStock.size(); i++)
	{
		if (inStock[i].getName() == name)
		{
			return inStock[i];
		}
	}
	Medicine medicine;
	return medicine;
}

void InquiryOffice::buy(std::string name)
{
	if (findByName(name).getName() == "не указанно")
	{
		std::cout << "Лекарства с таким названием нет в наличии" << std::endl;
	}
	else
	{
		Sale sale(findByName(name));
		sales.push_back(sale);
	}
}

int InquiryOffice::amountOfSalesInLastWeek(std::string name)
{
	int counter = 0;
	for (size_t i = 0; i < sales.size(); i++)
	{
		if (sales[i].getName() == name && sales[i].isWithinLastWeek())
		{ 
			counter++;
		}
	}
	return counter;
}

int InquiryOffice::amountOfSalesInLastMounth(std::string name)
{
	int counter = 0;
	for (size_t i = 0; i < sales.size(); i++)
	{
		if (sales[i].getName() == name && sales[i].isWithinLastMounth())
		{
			counter++;
		}
	}
	return counter;
}

int InquiryOffice::amountOfSalesInLastYear(std::string name)
{
	int counter = 0;
	for (size_t i = 0; i < sales.size(); i++)
	{
		if (sales[i].getName() == name && sales[i].isWithinLastYear())
		{
			counter++;
		}
	}
	return counter;
}