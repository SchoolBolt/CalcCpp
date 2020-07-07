#ifndef _SUBTRACTOPERATION_H_
#define _SUBTRACTOPERATION_H_

#include "BinaryOperation.h"

/**
 *  Операция вычитания
 */
class SubtractOperation : public BinaryOperation {
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
