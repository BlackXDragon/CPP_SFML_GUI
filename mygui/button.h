#if !defined(BUTTON_GUI_H)
#define BUTTON_GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include "widget.h"

namespace mygui {
	namespace textAlign {
		enum HorizonalAlign {
			Center, Left, Right
		};
		enum VerticalAlign {
			Middle, Top, Bottom
		};
	}

	class Button : public mygui::Widget {
		public:
			Button(sf::RenderWindow*);
			Button(sf::RenderWindow*, std::string);

			bool pressed = false;

			void draw();
			void poll();
			void setSize(float, float);
			void setFont(sf::Font);
			void setTextAlign(textAlign::HorizonalAlign align);
			void setTextValign(textAlign::VerticalAlign align);
			void setText(std::string);
			void setBg(sf::Color);
			void setPosition(float, float);
			sf::FloatRect getLocalBounds();
			sf::FloatRect getGlobalBounds();
		protected:
			sf::RenderWindow* window;
			std::string text;
			sf::Font font;
			sf::Text textWidget;
			sf::RectangleShape rect;
			textAlign::HorizonalAlign horizontalAlign = textAlign::Center;
			textAlign::VerticalAlign verticalAlign = textAlign::Middle;
			int x, y;
			float width, height;

			virtual void onclick() = 0;
	};
}

#endif // BUTTON_GUI_H
