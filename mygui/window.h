#if !defined(WINDOW_GUI_H)
#define WINDOW_GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include "widget.h"

namespace mygui {
	class Window {
		public:
			Window(unsigned int, unsigned int, std::string);
			void setFramerateLimit(unsigned int);
			void addWidget(mygui::Widget*, unsigned int);
			sf::Vector2u getSize();
			void show();
			sf::RenderWindow* getRenderWindow();
		protected:
			sf::RenderWindow rw;
			std::map<unsigned int, mygui::Widget*> widgets;
	};
}

#endif // WINDOW_GUI_H
