#ifndef _PARSERIMPL_H_
#define _PARSERIMPL_H_

/**
 * @file ParserImpl.h
 * Реализация парсера математических выражений по представленной
 * ниже грамматике
 *
 * BNF:
 * (https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)
 *
 * <expr> ::= <term> + <expr> | <term> - <expr> | <term>
 * <term> ::= <factor> * <term> | <factor> / <term> | <factor>
 * <factor> ::= ( <expr> ) | <number>
 *
 */

#include "../Expressions/Expression.h"
#include <string>

/**
 *  Парсер символа <expr> в представленной грамматике
 */
class ExprParser {
public:

    /**
     *  Метод проверяет применим ли символ <expr> к текущей позиции
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция
     *  @return истина, если применим, ложь -- в обратном случае
     */
    static bool isApplicable(const std::string &source, unsigned int pos);

    /**
     *  Метод выполянет разбор исходной строки, начиная с указанной позиции
     *  и заканчивая концом выражения
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция (изменяется)
     *  @return экземпляр Expression
     *  @throw ParserException, std::logic_error
     */
    static Expression *parse(const std::string &source, unsigned int &pos);
};

/**
 *  Парсер символа <term> в представленной грамматике
 */
class TermParser {
public:

    /**
     *  Метод проверяет применим ли символ <term> к текущей позиции
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция
     *  @return истина, если применим, ложь -- в обратном случае
     */
    static bool isApplicable(const std::string &source, unsigned int pos);

    /**
     *  Метод выполянет разбор исходной строки, начиная с указанной позиции
     *  и заканчивая концом выражения
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция (изменяется)
     *  @return экземпляр Expression
     *  @throw ParserException, std::logic_error
     */
    static Expression *parse(const std::string &source, unsigned int &pos);
};

/**
 *  Парсер символа <factor> в представленной грамматике
 */
class FactorParser {
public:

    /**
     *  Метод проверяет применим ли символ <factor> к текущей позиции
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция
     *  @return истина, если применим, ложь -- в обратном случае
     */
    static bool isApplicable(const std::string &source, unsigned int pos);

    /**
     *  Метод выполянет разбор исходной строки, начиная с указанной позиции
     *  и заканчивая концом выражения
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция (изменяется)
     *  @return экземпляр Expression
     *  @throw ParserException
     */
    static Expression *parse(const std::string &source, unsigned int &pos);
};

/**
 *  Парсер символа <number> в представленной грамматике
 */
class NumberParser {
public:

    /**
     *  Метод проверяет применим ли символ <number> к текущей позиции
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция
     *  @return истина, если применим, ложь -- в обратном случае
     */
    static bool isApplicable(const std::string &source, unsigned int pos);

    /**
     *  Метод выполянет разбор исходной строки, начиная с указанной позиции
     *  и заканчивая концом выражения
     *
     *  @param source строка с исходным математическим выражением
     *  @param pos текущая позиция (изменяется)
     *  @return экземпляр Expression
     *  @throw ParserException
     */
    static Expression *parse(const std::string &source, unsigned int &pos);
};

/**
 *  Функция пропуска пробелов в исходной строке, начиная с указанной позиции
 *
 *  @param source строка с исходным математическим выражением
 *  @param pos текущая позиция (изменяется)
 */
void skipSpaces(const std::string &source, unsigned int &pos);

#endif
