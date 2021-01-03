#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

enum switches {
    All_HOUSE_ELECTRICITY  = 1,
    MAIN_SOCKETS = 2,
    LIGHTS_INSIDE = 4,
    LIGHTS_GARDEN = 8,
    HEATER_INSIDE = 16,
    HEATER_PIPELINE = 32,
    CONDITIONER = 64
};

int main()
{
    int status = 0,
    T_out = 0,
    T_in = 0,
    DELTA_LUMEN = 575,
    lumen_currently = 5000;
    std::string input_string,
    movement,
    lights_inside_status;
    std::stringstream input_buffer;

    std::cout << "Type information using space between inputs like\n'T_out T_in "
                 "Movement Lights_inside'\n EXAMPLE >> 10 23 yes/no on/off\n\n";

    for(int day = 1; day <= 2; day++)
    {
        for (int hour = 0; hour < 24; hour++)
        {
            input_buffer.clear();
            input_string.clear();
            if(hour == 0) lumen_currently = 5000;

            std::cout << std::endl << "DAY " << day << ", HOUR " << hour << ":00\ninput parameters\n:";
            std::getline(std::cin, input_string);
            input_buffer << input_string;
            //std::cout << "CHECK STRINGS " << input_string << input_buffer.str() << std::endl;
            //Parsing
            input_buffer >> T_out >> T_in >> movement >> lights_inside_status;

            /*
            //CHECK PARSING
            if((T_out <= 0 || T_out > 0)
               && (T_in <= 0 || T_in > 0)
               && (movement == "yes" || movement == "no")
               && (lights_inside_status == "on" || lights_inside_status == "off"))
            {
                std::cout << "parsing OK\n\n";
            }
            */

            std::cout << "**********\n";

            //HEATER_PIPELINE section
            if(T_out < 0)
            {
                status = status | HEATER_PIPELINE;
                std::cout <<"HEATER_PIPELINE is on" << std::endl;
            }
            if(T_out > 5)
            {
                status = status & ~HEATER_PIPELINE;
                std::cout <<"HEATER_PIPELINE is off" << std::endl;
            }


            //LIGHTS_GARDEN section
            if ( ( (hour >= 0 && hour <= 5) || (hour >=16 && hour <= 23) )
                    && movement == "yes" )
            {
                status = status | LIGHTS_GARDEN;
                std::cout <<"LIGHTS_GARDEN is on" << std::endl;
            }
            else {
                status = status & ~LIGHTS_GARDEN;
                std::cout <<"LIGHTS_GARDEN is off" << std::endl;
            }


            //HEATER_INSIDE section
            if(T_in < 22)
            {
                status = status | HEATER_INSIDE;
                std::cout <<"HEATER_INSIDE is on" << std::endl;
            }
            if(T_in >= 25)
            {
                status = status & ~HEATER_INSIDE;
                std::cout <<"HEATER_INSIDE is off" << std::endl;
            }


            //CONDITIONER section
            if(T_in >= 30)
            {
                status = status | CONDITIONER;
                std::cout <<"CONDITIONER is on" << std::endl;
            }
            if(T_in <= 25)
            {
                status = status & ~CONDITIONER;
                std::cout <<"CONDITIONER is off" << std::endl;
            }


            //LIGHTS_INSIDE section with lumen adjustments
            if(lights_inside_status == "on")
            {
                status = status | LIGHTS_INSIDE;
                std::cout <<"LIGHTS_INSIDE is on" << std::endl;
                if( hour <= 20 && hour >= 16)
                {
                    lumen_currently -= DELTA_LUMEN * (hour-16);
                    std::cout <<"LUMEN intensity : " << lumen_currently << std::endl;
                }
                else if((hour >= 0 && hour < 16) || (hour > 20 && hour <24))
                {
                    std::cout <<"LUMEN intensity : " << lumen_currently << std::endl;
                }
            }
            else if(lights_inside_status == "off")
            {
                status = status & ~LIGHTS_INSIDE;
                std::cout <<"LIGHTS_INSIDE is off" << std::endl;
            }

            //END
            std::cout << "**********\n";
        }
    }

    return 1234;
}

