#pragma once
#include "Matrix.h"
#include "Generator.h"
/**
* @brief генератор чисел заполненяющий массив константным значением
*/
class FWConst :
    public Generator
{
private:
    int value;
public:
    /**
    * @brief конструктор
    * @param value значение которым будет заполнен массив
    */
    FWConst(const int value);
    /**
    * @brief метод возвращает значение поля value
    */
    int generate() override;
};
