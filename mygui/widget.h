#if !defined(WIDGET_H)
#define WIDGET_H

#include <SFML/Graphics.hpp>

namespace mygui {
	class Widget {
		public:
			virtual void draw(sf::RenderWindow*) = 0;
			virtual void poll(sf::RenderWindow*) = 0;
			virtual ~Widget() {}
	};
}

#endif // WIDGET_H
