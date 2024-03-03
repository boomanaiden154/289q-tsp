all: main.o DataLoader.o
	clang++ -O3 src/main.o src/DataLoader.o -o main

main.o: src/main.cpp
	clang++ -O3 src/main.cpp -I include -c -o src/main.o

DataLoader.o: src/DataLoader.cpp include/DataLoader.h
	clang++ -O3 src/DataLoader.cpp -I include -c -o src/DataLoader.o

clean:
	rm src/*.o
	rm main
