#ifndef _DIVIDE_OPERATION_H_
#define _DIVIDE_OPERATION_H_

#include "BinaryOperation.h"

/**
 *  Операция деления
 */
class DivideOperation : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation; // унаследованный конструктор

    /**
     * Метод вычисляет численное значение выражения
     *
     * @return значение выражения как вещественное число
     */
    double calculate() const override;
};

#endif
