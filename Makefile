all: main.o
	clang++ src/main.o -o main

main.o: src/main.cpp
	clang++ src/main.cpp -c -o src/main.o

clean:
	rm src/*.o
	rm main
