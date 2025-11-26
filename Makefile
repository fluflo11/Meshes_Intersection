all: build

.Phony : build run clean

build:
	g++ -o list_nodes src/*.cpp

run: 
	./list_nodes

clean: 
	rm list_nodes