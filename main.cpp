#include "mygui/window.h"
#include "mygui/button.h"
#include <iostream>

class myButton1 : public mygui::Button {
public:
    myButton1(std::string text) : mygui::Button(text) {}

    void onclick() override {
        if(this->pressed) {
            this->setText("I'm clicked!");
        } else {
            this->setText("Click me!");
        }
    }
};

int main()
{
    mygui::Window mywindow(400, 400, "My Window");
    mywindow.setFramerateLimit(30);

	sf::Font font;
	font.loadFromFile("Times New Roman 400.ttf");
	myButton1 button("Click Me!");
    button.setSize(180, 60);
	button.setBg(sf::Color::Red);
    // button.setFont(font);
    button.setTextAlign(mygui::textAlign::Right);
    button.setTextValign(mygui::textAlign::Middle);
    sf::Vector2u windowSize = mywindow.getSize();
    button.setPosition(windowSize.x/2-90, windowSize.y/2-30);
    mywindow.addWidget(&button, 1);

    mywindow.show();

    return 0;
}