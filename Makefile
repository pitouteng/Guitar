
SFML = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window 
BOOST = -lboost_unit_test_framework

all: guitarhero
guitarhero: RingBuffer.o GuitarString.o GuitarHero.o
	g++ -o guitarhero RingBuffer.o GuitarString.o GuitarHero.o $(SFML)

GuitarHero.o: GuitarHero.cpp
	g++ -c -Wall -ansi -pedantic GuitarHero.cpp -std=c++11

guitarherolite: RingBuffer.o GuitarString.o GuitarHeroLite.o
	g++ -o guitarherolite RingBuffer.o GuitarString.o GuitarHeroLite.o $(SFML)

GuitarHeroLite.o: GuitarHeroLite.cpp
	g++ -c -Wall -ansi -pedantic GuitarHeroLite.cpp -std=c++11

gstest: RingBuffer.o GuitarString.o GStest.o
	g++ -o gstest RingBuffer.o GuitarString.o GStest.o $(BOOST)

GStest.o: GStest.cpp
	g++ -c -Wall -ansi -pedantic GStest.cpp -std=c++11

GuitarString.o: GuitarString.hpp GuitarString.cpp
	g++ -c -Wall -ansi -pedantic GuitarString.cpp -std=c++11

RingBuffer.o: RingBuffer.hpp RingBuffer.cpp
	g++ -c -Wall -ansi -pedantic RingBuffer.cpp -std=c++11

clean:
	rm *.o gstest guitartherolite guitarhero




# CC = g++
# CFLAGS = -O1 -Wall -std=c++11 -lboost_unit_test_framework -lsfml-audio
# OBJECTS = RingBuffer.o GuitarString.o GStest.o
# all: GStest 

# GStest: $(OBJECTS)
# 	$(CC) -o GStest $(OBJECTS) $(CGFLAGS)

# GStest.o: GStest.cpp 
# 	$(CC) -c GStest.cpp 

# GuitarString.o: GuitarString.cpp GuitarString.hpp
# 	$(CC) -c -std=c++11 GuitarString.cpp

# RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
# 	$(CC) -c -std=c++11 RingBuffer.cpp
	
# clean:
# 	rm $(OBJECTS) test 

# target: dependencies
# 	action
