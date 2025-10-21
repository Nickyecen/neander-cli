CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
LDFLAGS  = -lncurses

SRCS = main.cpp \
			 neander.cpp \
       nwinman/neander_app.cpp \

OBJS = $(SRCS:.cpp=.o)          # keeps the directory part

main: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# pattern rule that honours the directory
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main $(OBJS)

.PHONY: clean
