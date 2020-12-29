#include <iostream>
#include <cstdio>
#include <climits>
enum switches
{
    floor_1 = 1,
    floor_2 = 2,
    floor_3 = 4,
    floor_4 = 8,
};

int main()
{
    int stat = 0;
    stat = stat | floor_1;
    std::cout << "stat1: " << stat << std::endl;
    stat = stat | floor_2;
    std::cout << "stat2: " << stat << std::endl;
    stat = stat | floor_4;
    std::cout << "stat4: " << stat << std::endl;


    if((stat & floor_2) == floor_2)
    {
        std::cout << "stat: " << stat << std::endl;
        std::cout << "floor_2: " << floor_2 << std::endl;
        std::cout << "floor 2 lights on" << std::endl;
    }


    return 0;
}
