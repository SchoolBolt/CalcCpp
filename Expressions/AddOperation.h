#ifndef _ADDOPERATION_H_
#define _ADDOPERATION_H_

#include "BinaryOperation.h"

/**
 *  Операция сложения
 */
class AddOperation : public BinaryOperation {
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
