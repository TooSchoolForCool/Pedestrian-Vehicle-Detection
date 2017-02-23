launch: main.o grabber.o
	g++ main.o grabber.o -o launch

main.o: main.cpp
	g++ -c main.cpp -o main.o

grabber.o: grabber.cpp
	g++ -c grabber.cpp -o grabber.o

run: launch
	./launch

clean:
	rm -f *.o
	rm launch