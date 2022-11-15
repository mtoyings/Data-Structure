all: openhttest orderedhttest

openhttest: openhttest.cpp openht.cpp openht.h
	g++ -std=c++11 -o openhttest openhttest.cpp openht.cpp 


orderedhttest: orderedhttest.cpp orderedht.cpp orderedht.h chainingList.h chainingList.cpp
	g++ -std=c++11 -o orderedhttest orderedhttest.cpp orderedht.cpp chainingList.cpp 

clean:
	rm openhttest orderedhttest