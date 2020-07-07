#ifndef _MULTIPLYOPERATION_H_
#define _MULTIPLYOPERATION_H_

#include "BinaryOperation.h"

/**
 *  Операция умножения
 */
class MultiplyOperation : public BinaryOperation {
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
