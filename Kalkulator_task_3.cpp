#include <cstring>
#include <iostream>
#include <string>

int main()
{
    std::string var;
    int space_counter = 0;
    char text_buf[100]={}, a_buf[100]={}, b_buf[100]={};
    double a, b, output;
    char symbol;

    std::cout << "Type the equation with\n+, -, /, * symbols: ";
    std::cin >> text_buf;
    std::cout << "String buffer has now '" << text_buf << "' equation" << std::endl;

    //check symbol
    for(int i = 0; i < std::strlen(text_buf); ++i)
    {
        if(text_buf[i] < '0' || text_buf[i] > '9')
        {
            symbol = text_buf[i];
            text_buf[i] = ' ';
            break;
        }
        if(text_buf[i] == ' ') break;
    }
    //std::cout << "String buffer has " << text_buf << " digits " << std::endl;
    //std::cout << "Operator is " << symbol <<std::endl;

    //check first digit
    for(int i = 0; text_buf[i] != ' '; i++)
    {
        a_buf[i] = text_buf[i];
        space_counter = i+1;
        //std::cout << "a_buf : " << a_buf << std::endl;
    }

    //check second digit
    for(int i = space_counter+1; i < std::strlen(text_buf); i++)
    {
        b_buf[i-space_counter-1] = text_buf[i];
        //std::cout << "b_buf : " << b_buf << std::endl;
    }

    a = atof(a_buf);
    b = atof(b_buf);

    if(symbol == '+')std::cout << "OUTPUT: " << a+b << std::endl;
    if(symbol == '-')std::cout << "OUTPUT: " << a-b << std::endl;
    if(symbol == '*')std::cout << "OUTPUT: " << a*b << std::endl;
    if(symbol == '/')std::cout << "OUTPUT: " << a/b << std::endl;

return 1234;
}