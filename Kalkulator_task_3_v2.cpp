#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string equation;
    std::stringstream buf;
    double a, b;
    char symbol;

    std::cout << "Type the equation with\n+, -, /, * symbols: ";
    std::getline(std::cin, equation);
    std::cout << "String has now '" << equation << "' equation" << std::endl;


    for(int i = 0; i < equation.length(); i++)
    {
        if(equation[i] < 48 || equation[i] > 57 || equation[i]=='.')
        {
            if(equation[i] < 48 || equation[i] > 57)
            {
                if(equation[i]=='.') {buf << equation[i]; continue;}
                buf << " ";
                buf << equation[i];
                i++;
                buf << " ";
            }
        }
        buf << equation[i];
    }

    buf >> a >> symbol >> b;

    if(symbol == '+')std::cout << "OUTPUT: " << a+b << std::endl;
    if(symbol == '-')std::cout << "OUTPUT: " << a-b << std::endl;
    if(symbol == '*')std::cout << "OUTPUT: " << a*b << std::endl;
    if(symbol == '/')std::cout << "OUTPUT: " << a/b << std::endl;

    return 1234;
}