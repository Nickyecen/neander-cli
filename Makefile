CXX = g++
CXXFLAGS = -Wall -lncurses

target: main

main: neander.o memory_window.o main.o
	$(CXX) $(CXXFLAGS) $^ -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c	

clean:
	rm main *.o
