CC = g++
CFLAG = -c

myprogram: main.o gludll.o
	$(CC) main.o gludll.o -o myprogram

gludll.o: gludll.cpp
	$(CC) $(CFLAG) gludll.cpp -o gludll.o

main.o: main.cpp
	$(CC) $(CFLAG) main.cpp -o main.o

clean:
	rm -rf *.o
	rm myprogram
	
