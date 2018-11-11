
CC = g++
CFLAGS = -O1 -Wall -std=c++0x -lboost_unit_test_framework
OBJECTS = RingBuffer.o GuitarString.o GStest.o
all: GStest 

GStest: $(OBJECTS)
	$(CC) -o GStest $(OBJECTS) $(CGFLAGS)

GStest.o: GStest.cpp 
	$(CC)	-c GStest.cpp

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) -c -std=c++11 GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c -std=c++0x RingBuffer.cpp

clean:
	rm $(OBJECTS) test 

# target: dependencies
# 	action
