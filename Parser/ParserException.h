#ifndef _PARSEREXCEPTION_H_
#define _PARSEREXCEPTION_H_

#include <stdexcept>

/**
 *  Исключительная ситуация, описывающая ошибку разбора
 *  математического выражения
 */
class ParserException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

#endif
