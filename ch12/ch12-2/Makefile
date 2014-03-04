ex12-2: pe12-2b.o pe12-2a.o
	cc -o ex12-2 pe12-2b.o pe12-2a.o

pe12-2a.o:pe12-2a.c pe12-2a.h
	cc -c pe12-2a.c 

pe12-2b.o:pe12-2b.c pe12-2a.h
	cc -c pe12-2b.c 

clean:
	rm *.o