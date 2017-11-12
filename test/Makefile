
clean:
	rm *.o all_tests

Location.o:
	g++ -std=c++11 -c ../src/Location.cpp

DArrayTest.o:
	g++ -std=c++11 -c DArrayTest.cpp

LocationTest.o:
	g++ -std=c++11 -c LocationTest.cpp

ZelduboyTestSuite.o:
	g++ -std=c++11 -c ZelduboyTestSuite.cpp

all_tests: DArrayTest.o LocationTest.o ZelduboyTestSuite.o Location.o
	g++ -std=c++11 DArrayTest.o LocationTest.o ZelduboyTestSuite.o Location.o -lcgreen -o all_tests
