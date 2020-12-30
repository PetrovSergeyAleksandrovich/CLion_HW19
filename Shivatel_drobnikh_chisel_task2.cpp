#include <sstream>
#include <iostream>

int main()
{
    std::string var;
    std::stringstream text_buf;
    double output, test_ref_1=1.1, test_ref_2=0.001;

    std::cout << "Type first part: ";
    std::cin >> var;
    text_buf << var << ".";

    std::cout << "Type second part: ";
    std::cin >> var;
    text_buf << var;

    text_buf >> output;

    //check test values for 1 and 1 inputs
    if(output == test_ref_1)
    {
        std::cout << "output now is DOUBLE type" << std::endl;
    }

    //real output
    std::cout<< "You have DOUBLE: " << output << std::endl;

    // second check
    output -= test_ref_2;
    std::cout << "output is DOUBLE with -" << test_ref_2 << " : " << output << std::endl;

    return 1234;
}