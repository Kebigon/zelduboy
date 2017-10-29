
clean:
	rm *.o all_tests

Location.o:
	g++ -std=c++11 -c ../src/Location.cpp

LocationTest.o:
	g++ -std=c++11 -c LocationTest.cpp

ZelduboyTestSuite.o:
	g++ -std=c++11 -c ZelduboyTestSuite.cpp

all_tests: LocationTest.o ZelduboyTestSuite.o Location.o
	g++ -std=c++11 LocationTest.o ZelduboyTestSuite.o Location.o -lcgreen -o all_tests
