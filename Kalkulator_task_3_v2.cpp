#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string equation;
    std::stringstream buf;
    double a, b, c;
    char symbol1, symbol2;

    std::cout << "Type the equation with\n+, -, /, * symbols: ";
    std::getline(std::cin, equation);
    std::cout << "String has now '" << equation << "' equation" << std::endl;

/*
    for(int i = 0; i < equation.length(); i++)
    {
        if(equation[i] < 48 || equation[i] > 57 || equation[i]=='.')
        {
            if(equation[i] < 48 || equation[i] > 57)
            {
                if(equation[i]=='.') {buf << equation[i]; continue;}
                buf << " ";
                buf << equation[i];
                buf << " ";
                continue;
            }
        }
        buf << equation[i];
    }
*/
    buf << equation; // ВМЕСТО ЦИКЛА !
    buf >> a >> symbol1 >> b >> symbol2 >> c;

    if(symbol1 == '+')std::cout << "OUTPUT: " << a+b+c << std::endl;
    if(symbol1 == '-')std::cout << "OUTPUT: " << a-b-c << std::endl;
    if(symbol1 == '*')std::cout << "OUTPUT: " << a*b*c << std::endl;
    if(symbol1 == '/')std::cout << "OUTPUT: " << a/b/c << std::endl;

    return 1234;
}