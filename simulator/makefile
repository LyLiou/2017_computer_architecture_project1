#make: make a executable file
#make o3: use -O3
#make clean: clean enough to submit
CC = g++
FLAGS = -std=c++11 -Wall

single_cycle: single_cycle.o instruction.o read_file.o init.o
	$(CC) -o single_cycle single_cycle.o instruction.o read_file.o init.o
single_cycle.o: single_cycle.cpp single_cycle.h
	$(CC) $(FLAGS) -c single_cycle.cpp
instruction.o: instruction.cpp single_cycle.h
	$(CC) $(FLAGS) -c instruction.cpp
read_file.o: read_file.cpp single_cycle.h
	$(CC) $(FLAGS) -c read_file.cpp
init.o: init.cpp single_cycle.h
	$(CC) $(FLAGS) -c init.cpp

clean:
	rm -f single_cycle *.o *.rpt