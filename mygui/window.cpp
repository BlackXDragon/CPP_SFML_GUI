#include "window.h"

mygui::Window::Window(unsigned int width, unsigned int height, std::string name) : rw(sf::VideoMode(width, height), name) {}

void mygui::Window::setFramerateLimit(unsigned int rate) {
	this->rw.setFramerateLimit(rate);
}

void mygui::Window::addWidget(mygui::Widget* widget, unsigned int z) {
	this->widgets.insert(std::pair<unsigned int, mygui::Widget*>(z, widget));
}

sf::Vector2u mygui::Window::getSize() {
	return this->rw.getSize();
}

void mygui::Window::show() {
	while (this->rw.isOpen()) {
		for (auto &i: this->widgets) {
			sf::Event event;
			while (this->rw.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->rw.close();
			}
			this->rw.clear();
			i.second->draw(&(this->rw));
			this->rw.display();
		}
	}
}

sf::RenderWindow* mygui::Window::getRenderWindow() {
	return &(this->rw);
}