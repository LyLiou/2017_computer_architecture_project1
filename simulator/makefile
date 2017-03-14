#make: make a executable file
#make o3: use -O3
#make clean: clean enough to submit
CC = g++
FLAGS = -std=c++11 -Wall

single_cycle: single_cycle.o instruction.o
	$(CC) -o single_cycle single_cycle.o instruction.o
single_cycle.o: single_cycle.cpp single_cycle.h
	$(CC) $(FLAGS) -c single_cycle.cpp
instruction.o: instruction.cpp single_cycle.h
	$(CC) $(FLAGS) -c instruction.cpp

clean:
	rm -f single_cycle *.o *.rpt