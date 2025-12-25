#pragma once
#include "Medicine.h"
#include "Sale.h"
#include <vector>
/**
* @brief справочная аптеки
*/
class InquiryOffice
{
private:
    std::vector<Medicine> inStock;
    std::vector<Sale> sales;
public:
    /**
    * @brief конструктор по умолчанию
    */
    InquiryOffice();
    /**
    * @brief конструктор
    * @param inStock массив лекарств
    */
    InquiryOffice(std::vector<Medicine> inStock);
    /**
    * @brief метод добавления лекарства в продажу
    * @param item лекарство
    */
    void addToStock(Medicine item);
    /**
    * @brief показать информацию о лекарстве
    * @param name название лекарства
    */
    void showInformation(std::string name);
    /**
    * @brief показать лекарства от болезни
    * @param illness название болезни
    */
    void showMedicine(std::string illness);
    /**
    * @brief метод нахождения лекаства по названию
    * @param name название лекарства
    */
    Medicine findByName(std::string name);
    /**
    * @brief метод покупки лекарства
    * @param name название лекарства
    */
    void buy(std::string name);
    /**
    * @brief метод возвращает количество продаж лекарства за неделю
    * @param name название лекарства
    */
    int amountOfSalesInLastWeek(std::string name);
    /**
    * @brief метод возвращает количество продаж лекарства за месяц
    * @param name название лекарства
    */
    int amountOfSalesInLastMounth(std::string name);
    /**
    * @brief метод возвращает количество продаж лекарства за год
    * @param name название лекарства
    */
    int amountOfSalesInLastYear(std::string name);
};

