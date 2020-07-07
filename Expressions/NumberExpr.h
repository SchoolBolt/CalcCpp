#ifndef _NUMBEREXPR_H_
#define _NUMBEREXPR_H_

#include "Expression.h"

/**
 *  Числовая константа как математическое выражение
 */
class NumberExpr : public Expression {
public:
    /**
     *  Конструктор
     *
     *  @param value значение числовой константы
     */
    NumberExpr(double value);

    /**
     * Метод вычисляет численное значение выражения
     *
     * @return значение выражения как вещественное число
     */
    double calculate() const override;

private:
    double _value;
};

#endif
