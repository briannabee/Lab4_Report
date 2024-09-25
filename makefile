a.exe: Node.o Stack.o Queue.o test.o
	g++ Node.o Stack.o Queue.o test.o

Node.o: Node.h Node.cpp
	g++ -c -g Node.cpp

Stack.o: Node.h Stack.h Stack.cpp
	g++ -c -g Stack.cpp

Queue.o: Node.h Queue.h Queue.cpp
	g++ -c -g Queue.cpp

test.o: Stack.h test.cpp
	g++ -c -g test.cpp

clean:
	del *.o a.exe
