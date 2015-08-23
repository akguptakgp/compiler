a.out: ass3_12CS10006.o lex.yy.o y.tab.o 
	cc ass3_12CS10006.o lex.yy.o y.tab.o -lfl 
y.tab.o: y.tab.c
	cc -c y.tab.c
y.tab.c: ass3_12CS10006.y
	yacc -dtv ass3_12CS10006.y
lex.yy.o: lex.yy.c y.tab.o 
	cc -c lex.yy.c
lex.yy.c: ass3_12CS10006.l
	flex ass3_12CS10006.l
ass3_12CS10006.o: ass3_12CS10006.c
	cc -c ass3_12CS10006.c
clean:
	rm lex.yy.c lex.yy.o a.out y.tab.o y.tab.c ass3_12CS10006.o y.tab.h
