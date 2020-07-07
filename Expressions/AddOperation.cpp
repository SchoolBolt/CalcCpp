#include "AddOperation.h"

double AddOperation::calculate() const {
    return _left->calculate() + _right->calculate();
}
