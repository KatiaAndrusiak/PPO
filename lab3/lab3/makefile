#CXX = g++
#CFLAGS = -Wall -g
#SRC=$(wildcard *.cpp)
#OBJ=$(SRC:.cpp=.o)
#all:program
#program:$(OBJ)
#	$(CXX) $(CFLAGS) $^ -o $@
#%.o:%.cpp %.h
#	$(CXX) $(CFLAGS) -c $<
#%.o:%.cpp
#	$(CXX) $(CFLAGS) -c $<
all: program 
program: main.o binary.o mystring.o cipher.o xor.o
	g++ -g -Wall main.o binary.o mystring.o cipher.o xor.o  -o exec

main.o:main.cpp mystring.h cipher.h binary.h xor.h
	g++ -c -g -Wall main.cpp -o main.o

binary.o:binary.cpp binary.h
	g++ -c -g -Wall binary.cpp -o binary.o

mystring.o:mystring.cpp mystring.h
	g++ -c -g -Wall mystring.cpp -o mystring.o

chiper.o:chiper.cpp cipher.h xor.h
	g++ -c -g -Wall cipher.cpp -o cipher.o

xor.o:xor.cpp  xor.h
	g++ -c -g -Wall xor.cpp -o xor.o
clean:
	rm -rf main.o binary.o mystring.o cipher.o xor.o exec
.PHONY: clean all


