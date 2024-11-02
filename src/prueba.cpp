#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main()
{
    std::string reset_position;
    int frame = 0;
    int paletaPosition = 30; 

    while (true)
    {
        auto can = Canvas(500, 500);

        can.DrawBlockLine(151, 50, 151, 100);
        can.DrawBlockLine(150, 50, 150, 100);
        can.DrawBlockLine(149, 50, 149, 100);

        can.DrawBlockCircleFilled(150, paletaPosition, 25, Color::DarkBlue);
        can.DrawBlockCircleFilled(140, paletaPosition, 25, Color::DarkBlue);
        can.DrawBlockCircleFilled(160, paletaPosition, 25, Color::DarkBlue);
        can.DrawBlockCircleFilled(150, paletaPosition + 2, 25, Color::DarkBlue);
        can.DrawBlockCircleFilled(150, paletaPosition - 2, 25, Color::DarkBlue);

        paletaPosition++;
    
        if (paletaPosition > 100) {
            paletaPosition = 30; 
        }

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Blue3, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}
