#ifndef _PARSER_H_
#define _PARSER_H_

#include "../Expressions/Expression.h"
#include <string>

/**
 *  Класс разбора математического выражения как строки
 */
class Parser {
public:

    /**
     *  Конструктор
     *
     *  @param source строка, содержащая математическое выражение
     */
    Parser(const std::string &source);

    /**
     *  Метод преобразует строку, переданную в конструктор,
     *  в дерево операндов и возвращает указатель на корневой
     *  элемент.
     *
     *  @return указатель на корневой элемент дерева операндов
     *
     *  @see Parser()
     */
    Expression *parse() const;

private:
    const std::string &_source;
};

#endif
