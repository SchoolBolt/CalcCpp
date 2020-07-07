#include "Parser.h"
#include "ParserImpl.h"
#include "ParserException.h"
#include <sstream>

Parser::Parser(const std::string &source) :
    _source(source)
{}

Expression *Parser::parse() const {
    unsigned int pos = 0;
    skipSpaces(_source, pos);
    if (!ExprParser::isApplicable(_source, pos)) {
        throw ParserException("Not a valid expression");
    }

    Expression *result = ExprParser::parse(_source, pos);

    skipSpaces(_source, pos);
    if (pos != _source.size()) {
        std::stringstream ss;
        ss << "Unexpected symbols at the end of expression after " << pos;
        delete result;
        throw ParserException(ss.str());
    }

    return result;
}
