#make: make a executable file
#make o3: use -O3
#make clean: clean enough to submit
CC = g++
FLAGS = -std=c++11 -Wall -O2
HEADER = single_cycle.h
OBJS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

single_cycle: $(OBJS)
	$(CC) -o single_cycle $(OBJS)
%.o: $(HEADER) %.cpp
	$(CC) $(FLAGS) -c $^
debug: $(HEADER)
	$(CC) -g $(FLAGS) $(wildcard *.cpp)

clean:
	rm -f single_cycle *.o *.rpt *.out