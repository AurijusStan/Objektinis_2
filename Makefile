main: funkcijos.o
	g++ -o prog Vector.cpp funkcijos.o -O3
funkcijos: funkcijos.cpp
	g++ -c funkcijos.cpp -o funkcijos.o
clean:
	del *.o prog.exe