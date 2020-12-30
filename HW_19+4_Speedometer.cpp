#include <iostream>
#include <sstream>

int main()
{
    double delta_speed = 0,
    MAX_SPEED = 150;
    double DELTA = 0.01,
    current_speed = 0;
    std::stringstream text;


    std::cout << "\nType the speed increase or decrease: ";
    std::cin >> delta_speed;

    current_speed += delta_speed;
    if(current_speed > MAX_SPEED) current_speed = MAX_SPEED;

    text << current_speed;
    std::cout << "Current speed: " << text.str() << " m/s" << std::endl;
    text.str("");


    while (current_speed > DELTA)
    {
        std::cout << "\nType the speed increase or decrease: ";
        std::cin >> delta_speed;

        current_speed += delta_speed;
        if(current_speed > MAX_SPEED) current_speed = MAX_SPEED;

        text << current_speed;
        std::cout << "Current speed: " << text.str() << " m/s" << std::endl;
        text.str("");
    }

    std::cout << "\nCAR STOPPED";
    return 1234;
}