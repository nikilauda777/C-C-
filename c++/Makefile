OBJS	= programm.o
SOURCE	= programm.cpp
HEADER	= gebiet.h stadt.h strasse.h randomtrip.h
OUT	= programm
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

programm.o: programm.cpp
	$(CC) $(FLAGS) programm.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)