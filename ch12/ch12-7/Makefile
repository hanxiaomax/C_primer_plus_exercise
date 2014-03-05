ex12-7:12-7.o diceroll.o 
	cc -o ex12-7 12-7.o diceroll.o

12-7.o:12-7.c diceroll.h
	cc -c 12-7.c

diceroll.o:diceroll.c diceroll.h
	cc -c diceroll.c
clean:
	rm *.o
