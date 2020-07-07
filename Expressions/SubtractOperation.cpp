#include "SubtractOperation.h"

double SubtractOperation::calculate() const {
    return _left->calculate() - _right->calculate();
}
