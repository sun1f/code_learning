#手写makefile文件

GXX = g++
CFLAGS = -lm -Wall -g

main: ./src/main.cpp helloslam.o
	$(GXX) $(CFLAGS) ./src/main.cpp helloslam.o -o main

helloslam.o: ./include/helloslam.h ./src/helloslam.cpp
	$(GXX) $(CFLAGS) -c ./src/helloslam.cpp ./include/helloslam.h
	

	
clean:
	rm *.o ./include/*.gch main
