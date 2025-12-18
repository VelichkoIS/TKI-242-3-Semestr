#pragma once
#include "Generator.h"
#include "Matrix.h"
/**
* @brief генератор чисел заполняющий массив нулями
*/
class FWZeroes :
    public Generator
{ 
    public:
    /**
    * @brief возвращает ноль
    */
    int generate() override;
};

