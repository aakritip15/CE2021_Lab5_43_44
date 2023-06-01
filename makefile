all:
	g++ -I include/ main.cpp src/* -o ./build/release

	./build/release
