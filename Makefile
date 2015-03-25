all:	main

main: main.o Guy.o
	g++ main.o Guy.o -w -lSDL2 -lSDL2_image -o main

main.o: main.cpp 
	g++ -c main.cpp

Guy.o: Guy.cpp
	g++ -c Guy.cpp

clean:
	rm -f *.o main
