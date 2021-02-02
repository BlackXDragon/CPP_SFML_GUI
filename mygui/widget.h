#if !defined(WIDGET_H)
#define WIDGET_H

namespace mygui {
	class Widget {
		public:
			virtual void draw() = 0;
			virtual ~Widget();
	};
}

#endif // WIDGET_H
