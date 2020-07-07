#include "ParserImpl.h"
#include "ParserException.h"
#include "../Expressions.h"
#include <sstream>
#include <stdexcept>

static std::string format_exception(const char *what, unsigned int pos) {
    std::stringstream ss;
    ss << "Invalid " << what << " at " << pos;
    return ss.str();
}

static std::string format_expected(const char *what, unsigned int pos) {
    std::stringstream ss;
    ss << "Expected " << what << " at " << pos;
    return ss.str();
}

bool ExprParser::isApplicable(const std::string &source, unsigned int pos) {
    return TermParser::isApplicable(source, pos);
}

Expression *ExprParser::parse(const std::string &source, unsigned int &pos) {
    Expression *left = TermParser::parse(source, pos);
    skipSpaces(source, pos);
    if (pos == source.size()) return left;

    if (source[pos] == '+' || source[pos] == '-') {
        char op = source[pos];
        pos++;
        skipSpaces(source, pos);
        if (!ExprParser::isApplicable(source, pos)) {
            delete left;
            throw ParserException(format_exception("expression", pos));
        }
        Expression *right = ExprParser::parse(source, pos);

        switch (op) {
        case '+': return new AddOperation(left, right);
        case '-': return new SubtractOperation(left, right);
        }

        throw std::logic_error("Invalid parser state");
    }

    return left;
}

bool TermParser::isApplicable(const std::string &source, unsigned int pos) {
    return FactorParser::isApplicable(source, pos);
}

Expression *TermParser::parse(const std::string &source, unsigned int &pos) {
    Expression *left = FactorParser::parse(source, pos);
    skipSpaces(source, pos);
    if (pos == source.size()) return left;

    if (source[pos] == '*' || source[pos] == '/') {
        char op = source[pos];
        pos++;
        skipSpaces(source, pos);
        if (!TermParser::isApplicable(source, pos)) {
            delete left;
            throw ParserException(format_exception("term", pos));
        }
        Expression *right = TermParser::parse(source, pos);

        switch (op) {
        case '*': return new MultiplyOperation(left, right);
        case '/': return new DivideOperation(left, right);
        }

        throw std::logic_error("Invalid parser state");
    }

    return left;
}

bool FactorParser::isApplicable(const std::string &source, unsigned int pos) {
    if (pos >= source.size()) return false;
    return source[pos] == '(' || NumberParser::isApplicable(source, pos);
}

Expression *FactorParser::parse(const std::string &source, unsigned int &pos) {
    if (source[pos] == '(') {
        pos++;
        skipSpaces(source, pos);
        if (!ExprParser::isApplicable(source, pos)) {
            throw ParserException(format_exception("expression", pos));
        }
        Expression *expr = ExprParser::parse(source, pos);
        skipSpaces(source, pos);
        if (pos == source.size() || source[pos] != ')') {
            delete expr;
            throw ParserException(format_expected(")", pos));
        }
        pos++;
        return expr;
    }

    return NumberParser::parse(source, pos);
}

bool NumberParser::isApplicable(const std::string &source, unsigned int pos) {
    if (pos >= source.size()) return false;
    return source[pos] >= '0' && source[pos] <= '9';
}

Expression *NumberParser::parse(const std::string &source, unsigned int &pos) {
    unsigned int start = pos;
    while (isApplicable(source, pos)) pos++;
    if (pos < source.size() && source[pos] == '.') {
        pos++;
        if (!isApplicable(source, pos)) {
            throw ParserException(format_expected("digit", pos));
        }
        while (isApplicable(source, pos)) pos++;
    }
    double value = std::stod(source.substr(start, pos-start));
    return new NumberExpr(value);
}

void skipSpaces(const std::string &source, unsigned int &pos) {
    while (pos < source.size() && source[pos] == ' ') pos++;
}
