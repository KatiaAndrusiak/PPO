all: program clean 

run: program
	./exec

program: main.o
	g++  main.o -o exec

main.o: main.cpp
	g++ -c -Wall  main.cpp -o main.o

clean:
	rm -rf main.o exec	
.PHONY: clean all run