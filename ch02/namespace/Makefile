app.out : main.o kitae.o mike.o
	g++ -o app.out main.o kitae.o mike.o

main.o : main.cpp
	g++ -c main.cpp

kitae.o : kitae.cpp
	g++ -c kitae.cpp -o kitae.o


mike.o : mike.cpp
	g++ -c mike.cpp -o mike.o

clean :
	rm -f *.o app.out 