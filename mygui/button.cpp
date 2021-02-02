#include "button.h"

mygui::Button::Button(sf::RenderWindow* window) {
	this->window = window;
	this->text = "New Button";
	this->font.loadFromFile("Roboto-Italic.ttf");
	this->textWidget.setFont(this->font);
	this->textWidget.setString(this->text);
	this->width = 150;
	this->height = 40;
	this->rect = sf::RectangleShape(sf::Vector2f(150, 40));
	this->rect.setFillColor(sf::Color::Blue);
	this->setPosition(this->x, this->y);
}

mygui::Button::Button(sf::RenderWindow* window, std::string text) {
	this->window = window;
	this->text = text;
	this->font.loadFromFile("Roboto-Italic.ttf");
	this->textWidget.setFont(this->font);
	this->textWidget.setString(this->text);
	this->width = 150;
	this->height = 40;
	this->rect = sf::RectangleShape(sf::Vector2f(150, 40));
	this->rect.setFillColor(sf::Color::Blue);
	this->setPosition(this->x, this->y);
}

void mygui::Button::draw() {
	window->draw(this->rect);
	window->draw(this->textWidget);
}

void mygui::Button::poll() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::FloatRect myBounds = this->getGlobalBounds();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (mousePos.x > myBounds.left && mousePos.x < (myBounds.left+myBounds.width)) && (mousePos.y > myBounds.top && mousePos.y < (myBounds.top+myBounds.height))) {
		this->pressed = true;
	} else {
		this->pressed = false;
	}
	this->onclick();
}

void mygui::Button::setSize(float width, float height) {
	this->width = width;
	this->height = height;
	this->rect.setSize(sf::Vector2f(width, height));
	this->setPosition(this->x, this->y);
}

void mygui::Button::setFont(sf::Font font) {
	this->font = font;
	this->textWidget.setFont(this->font);
}

void mygui::Button::setTextAlign(mygui::textAlign::HorizonalAlign align) {
	this->horizontalAlign = align;
}

void mygui::Button::setTextValign(mygui::textAlign::VerticalAlign align) {
	this->verticalAlign = align;
}

void mygui::Button::setText(std::string text) {
	this->text = text;
	this->textWidget.setString(this->text);
}

void mygui::Button::setBg(sf::Color color) {
	this->rect.setFillColor(color);
}

void mygui::Button::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
	this->rect.setPosition(sf::Vector2f(x, y));
	sf::FloatRect myBounds = this->rect.getGlobalBounds();
	sf::FloatRect textBounds = this->textWidget.getLocalBounds();
	float xText, yText;
	if(this->horizontalAlign == mygui::textAlign::Center) {
		xText = myBounds.left+(myBounds.width/2)-textBounds.width/2;
	} else if(this->horizontalAlign == mygui::textAlign::Left) {
		xText = myBounds.left + 3;
	} else if(this->horizontalAlign == mygui::textAlign::Right) {
		xText = myBounds.left + myBounds.width - textBounds.width - 3;
	}
	if(this->verticalAlign == mygui::textAlign::Middle) {
		yText = myBounds.top+(myBounds.height/2)-textBounds.height/2;
	} else if(this->verticalAlign == mygui::textAlign::Top) {
		yText = myBounds.top+3;
	} else if(this->verticalAlign == mygui::textAlign::Bottom) {
		yText = myBounds.top + myBounds.height -textBounds.height - 3;
	}
	this->textWidget.setPosition(xText, yText);
}

sf::FloatRect mygui::Button::getLocalBounds() {
	return this->rect.getLocalBounds();
}

sf::FloatRect mygui::Button::getGlobalBounds() {
	return this->rect.getGlobalBounds();
}