#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(const Expression *left, const Expression *right) :
    _left(left),
    _right(right)
{}

BinaryOperation::~BinaryOperation() {
    delete _left;
    delete _right;
}
