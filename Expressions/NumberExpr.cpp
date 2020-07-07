#include "NumberExpr.h"

NumberExpr::NumberExpr(double value) :
    _value(value)
{}

double NumberExpr::calculate() const {
    return _value;
}
