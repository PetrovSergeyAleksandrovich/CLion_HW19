#include <iostream>
#include <sstream>
#include <string>

enum notes {DO = 1, RE, MI, FA, SOL, LA, SI};

int main()
{

    std::stringstream input_buf;
    std::string text;
    char * buf[512]={};
    int x;

    std::cout << "Type 12 note combination by pressing numbers from 1 to 7" << std::endl;

    for(int i=0; i < 3; i++)
    {
        std::cout << "Combination " << i << " :";
        std::cin >> x;
        input_buf << x;
    }

    std::cout << input_buf.str() << std::endl;





/*
    notes single_note = DO;
    if(single_note == 1)
    {
        std::cout << "DO" << " ";
    }

    single_note = RE;
    if(single_note == 2)
    {
        std::cout << "RE" << " ";
    }
*/
    return 0;
}