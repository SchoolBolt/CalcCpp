#include "MultiplyOperation.h"

double MultiplyOperation::calculate() const {
    return _left->calculate() * _right->calculate();
}
