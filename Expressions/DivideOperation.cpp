#include "DivideOperation.h"
#include <stdexcept>

double DivideOperation::calculate() const {
    double numerator = _left->calculate();
    double denominator = _right->calculate();
    if (denominator == 0) {
        throw std::domain_error("Division by zero");
    }
    return numerator / denominator;
}
