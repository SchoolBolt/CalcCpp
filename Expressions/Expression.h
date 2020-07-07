#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

/** @interface Expression
 *  Общий предок всех математических выражений
 */
class Expression {
public:
    virtual ~Expression() = default; // виртуальный деструктор по-умолчанию

    /**
     * Метод вычисляет численное значение выражения
     *
     * @return значение выражения как вещественное число
     */
    virtual double calculate() const = 0;
};

#endif
