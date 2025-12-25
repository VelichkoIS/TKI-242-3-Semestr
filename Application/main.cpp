#include <iostream>
#include "C:\Users\1\source\repos\TKI-242-3-Semestr\Pharmacy\ClassLibrary\InquiryOffice.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "ru");
	InquiryOffice pharmacy;
	Medicine item1("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
	Medicine item2("Цетрин", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания2", "аллергия");
	pharmacy.addToStock(item1);
	pharmacy.addToStock(item2);
	pharmacy.showInformation("Зиртек");
	pharmacy.buy("Зиртек");
	pharmacy.buy("Цетрин");
	std::cout << "Продажи за неделю " << pharmacy.amountOfSalesInLastWeek("Зиртек") << std::endl;
	std::cout << "Продажи за месяц " << pharmacy.amountOfSalesInLastMounth("Зиртек") << std::endl;
	std::cout << "Продажи за год " << pharmacy.amountOfSalesInLastYear("Зиртек") << std::endl;
	std::cout << "Список лекарств от аллергии: ";
	pharmacy.showMedicine("аллергия");
}