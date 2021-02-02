#include <SFML/Graphics.hpp>
#include "mygui/button.h"
#include <iostream>

class myButton1 : public mygui::Button {
public:
    myButton1(sf::RenderWindow* window) : mygui::Button(window) {}
    myButton1(sf::RenderWindow* window, std::string text) : mygui::Button(window, text) {}

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
    sf::RenderWindow window(sf::VideoMode(400, 400), "Form test!");
    window.setFramerateLimit(60);
    sf::RectangleShape bg(sf::Vector2f(400, 400));
    bg.setFillColor(sf::Color::Black);

	sf::Font font;
	font.loadFromFile("Times New Roman 400.ttf");
	myButton1 button(&window, "Click Me!");
    button.setSize(180, 60);
	button.setBg(sf::Color::Red);
    // button.setFont(font);
    button.setTextAlign(mygui::textAlign::Right);
    button.setTextValign(mygui::textAlign::Middle);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		sf::Vector2u windowSize = window.getSize();

		button.setPosition(windowSize.x/2-90, windowSize.y/2-30);

        button.poll();

        window.clear();
        window.draw(bg);
		button.draw();
        window.display();
    }

    return 0;
}