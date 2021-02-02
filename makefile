mygui/Roboto-Italic.h: mygui/Roboto-Italic.ttf
	@xxd -i mygui/Roboto-Italic.ttf > mygui/Roboto-Italic.h
	@printf '#if !defined(ROBOTO_ITALIC_H)\n#define ROBOTO_ITALIC_H\n' | cat - mygui/Roboto-Italic.h > temp && mv temp mygui/Roboto-Italic.h
	@printf '#endif' | cat mygui/Roboto-Italic.h - > temp && mv temp mygui/Roboto-Italic.h
	@sed -i 's/\(unsigned.*\)/const \1/' mygui/Roboto-Italic.h

mygui/button.o: mygui/button.cpp mygui/button.h mygui/Roboto-Italic.h
	@g++ -o mygui/button.o -c mygui/button.cpp

mygui/window.o: mygui/window.cpp mygui/window.h
	@g++ -o mygui/window.o -c mygui/window.cpp

main: main.cpp mygui/button.o mygui/window.o
	@g++ -o main main.cpp mygui/button.o mygui/window.o -lsfml-graphics -lsfml-window -lsfml-system

test: main
	@./main

clean:
	@rm -rf main mygui/*.o mygui/Roboto-Italic.h