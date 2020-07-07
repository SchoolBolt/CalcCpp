#ifndef _BINARYOPERATION_H_
#define _BINARYOPERATION_H_

#include "Expression.h"

/**
 *  Общий предок для бинарных операторов
 */
class BinaryOperation : public Expression {
public:
    /**
     *  Конструктор
     *  Обычно наследуется без изменений в классах конкретных операций.
     *  Принимает во владение свои параметры
     *
     *  @param left левый операнд
     *  @param right правый операнд
     */
    BinaryOperation(const Expression *left, const Expression *right);

    /**
     *  Деструктор
     *  Освобождает память, занимаемую выражениями-операндами
     */
    ~BinaryOperation();

protected:
    const Expression *_left;
    const Expression *_right;
};

#endif
