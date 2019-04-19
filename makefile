ant: main.o AntStep.o inputVal.o
	g++ -std=c++0x main.o AntStep.o inputVal.o -o ant
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
AntStep.o: AntStep.cpp AntStep.h
	g++ -std=c++0x -c AntStep.cpp
	
inputVal.o: inputVal.cpp inputVal.h
	g++ -std=c++0x -c inputVal.cpp

.PHONY: clean

clean:
	rm *.o ant