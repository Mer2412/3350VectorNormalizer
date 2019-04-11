all: mid19 unittest

mid19: mid19.cpp
	g++ mid19.cpp -omid19

unittest: mid19.cpp data.cpp
	g++ mid19.cpp data.cpp -Wall -Wextra -ounittest -DUTEST

clean:
	rm -f mid19
	rm -f unittest
	rm -f *.o