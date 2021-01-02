#include <iostream>
#include <sstream>
#include <string>

enum notes {DO=49, RE, MI, FA, SOL, LA, SI};

int main()
{
    std::stringstream input_buf;
    std::string text;
    int x;

    std::cout << "Type 12 note combination by pressing numbers from 1 to 7" << std::endl;

    for(int i=0; i < 12; i++)
    {
        std::cout << "Combination " << i << " :";
        std::cin >> x;
        input_buf << x;
    }

    input_buf >> text;

    for(int i=0; i < text.length(); i++)
    {
        if(text[i] == DO) std::cout << "DO" << " ";
        if(text[i] == RE) std::cout << "RE" << " ";
        if(text[i] == MI) std::cout << "MI" << " ";
        if(text[i] == FA) std::cout << "FA" << " ";
        if(text[i] == SOL)std::cout << "SOL"<< " ";
        if(text[i] == LA) std::cout << "LA" << " ";
        if(text[i] == SI) std::cout << "SI" << " ";
    }

    return 0;
}