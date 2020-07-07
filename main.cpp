
#include "Expressions.h"
#include "Parser.h"
#include <iostream>

int main() {
    std::string expr_str;
    std::cout << "Please, enter the mathematical expression containing floating point numbers, operations +, -, *, / or ():\n> " << std::flush;
    std::getline(std::cin, expr_str);

    Parser parser(expr_str);

    try {
        Expression *expr = parser.parse();
        std::cout << expr->calculate() << std::endl;
    } catch (ParserException &pex) {
        std::cout << "Parser error: " << pex.what() << std::endl;
    } catch (std::domain_error &dex) {
        std::cout << "Calculation error: " << dex.what() << std::endl;
    } catch (std::logic_error &lex) {
        std::cout << "Programmer error: " << lex.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown error" << std::endl;
    }

    std::cout << "Press <Enter> key to exit..." << std::flush;
    std::cin.get();

    return 0;
}
