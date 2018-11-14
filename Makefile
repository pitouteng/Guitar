
CC = g++
CFLAGS = -O1 -Wall -ansi -pedantic -std=c++11 
SFML = lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
BOOST = -lboost_unit_test_framework
OBJECTS = RingBuffer.o GuitarString.o GStest.o GuitarHeroLite.o


all: GStest 

# GuitarHeroLite: RingBuffer.o GuitarString.o GuitarHeroLite.o
# 	$(CC) -o $(SFML) GuitarHeroLite RingBuffer.o GuitarString.o GuitarHeroLite.o 
# GuitarHeroLite.o: GuitarHeroLite.cpp
# 	$(CC) -c -std=c++11 GuitarHeroLite.cpp

GStest: $(OBJECTS)
	$(CC) -o GStest $(OBJECTS) $(CFLAGS)

GStest.o: GStest.cpp 
	$(CC) -c GStest.cpp 

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) -c $(CFLAGS) GuitarString.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c $(CFLAGS) RingBuffer.cpp
	
clean:
	rm $(OBJECTS) test 

# target: dependencies
# 	action
