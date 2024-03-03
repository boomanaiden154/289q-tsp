all: main.o DataLoader.o TSPUtils.o TSPAlgorithms.o
	clang++ -g -O3 src/main.o src/DataLoader.o src/TSPUtils.o src/TSPAlgorithms.o -o main

main.o: src/main.cpp
	clang++ -g -O3 src/main.cpp -I include -c -o src/main.o

DataLoader.o: src/DataLoader.cpp include/DataLoader.h
	clang++ -g -O3 src/DataLoader.cpp -I include -c -o src/DataLoader.o

TSPUtils.o: src/TSPUtils.cpp include/TSPUtils.h
	clang++ -g -O3 src/TSPUtils.cpp -I include -c -o src/TSPUtils.o

TSPAlgorithms.o: src/TSPAlgorithms.cpp include/TSPAlgorithms.h
	clang++ -g -O3 src/TSPAlgorithms.cpp -I include -c -o src/TSPAlgorithms.o

clean:
	rm src/*.o
	rm main
