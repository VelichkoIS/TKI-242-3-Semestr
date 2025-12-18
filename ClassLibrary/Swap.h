#pragma once
#include "Exercise.h"
#include "Matrix.h"
/**
* @brief задание 1
*/
class Swap :
    public Exercise
{
public:
    /**
    * @brief конструктор
    * @param array массив
    * @param gen генератор наполнения
    */
    Swap(Matrix<int>& array, Generator& gen);
    /**
    * @brief выводит содержимое массива
    */
    void showArray();
    /**
    * @brief находим элемент с наибольшим по модулю значением
    */
    size_t findMaxM();
    /**
    * @brief меняет местами два жлемента
    * @param first первый элемент
    * @param second второй жлемент
    */
    void swap_two_elements(int& first, int& second);
    /**
    * @brief меняет местами предпоследний и максимальный по модулю элементы
    */
    void Task1() override;
    /**
    * @brief реализация интерфейса
    */
    void Task2() override;
};

