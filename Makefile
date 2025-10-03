CXX = g++
CXXFLAGS = -Wall -lncurses

target: main

main: neander.o main.o
	%(CXX) neander.o main.o -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c	

clean:
	rm main *.o
