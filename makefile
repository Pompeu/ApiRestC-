CC = g++
STD = -std=c++14
LINKERFLAGS = -lpthread -lboost_system
COMPILEFLAGS = -I../crow/include
all:
	$(CC) $(STD) main.cpp -o main $(COMPILEFLAGS) $(LINKERFLAGS)