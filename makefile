button.o:
	@g++ -o mygui/button.o -c mygui/button.cpp

main: main.cpp mygui/button.o
	@g++ -o main main.cpp mygui/button.o

test: main
	@./main

clean:
	@rm -rf main mygui/button.o