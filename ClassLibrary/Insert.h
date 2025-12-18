#pragma once
#include "Exercise.h"
#include "Matrix.h"
/**
 * @brief упражнение 2
 */
class Insert :
    public Exercise
{
public:
    /**
    * @brief конструктор
    * @param array массив
    * @param gen генератор
    */
    Insert(Matrix<int>& array, Generator& gen);
    void showArray();
    /**
    * @brief вставляет элемент в массив
    * @param index индекс элемента массива
    * @param value значение элемента
    */
    void elementInsertion(size_t index,const int value);
    /**
    * @brief вставляет в массив по одному элементу равному последней цифре элемента массива сздади и спереди
    */
    void Task1() override;
    /**
    * @brief реализация интерфейса
    */
    void Task2() override;
};
