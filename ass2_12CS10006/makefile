a.out: main.o libass2_12CS10006.a
	cc -m32 main.o -L. -lass2_12CS10006
main.o: main.c myl.h
	cc -Wall -m32 -c main.c
libass2_12CS10006.a: ass2_12CS10006.o
	ar -rcs libass2_12CS10006.a ass2_12CS10006.o
ass2_12CS10006.o: ass2_12CS10006.c myl.h
	cc -Wall -m32 -c ass2_12CS10006.c
clean:
	rm a.out main.o libass2_12CS10006.a ass2_12CS10006.o
