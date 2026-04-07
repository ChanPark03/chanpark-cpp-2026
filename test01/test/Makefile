app.out : main.o a.o b.o
	gcc -o app.out main.o a.o b.o

main.o : main.c
	gcc -c main.c

a.o : a.c
	gcc -c a.c

b.o : b.c
	gcc -c b.c -o b.o

clean :
	rm -f *.o app.out