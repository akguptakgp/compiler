a.out:  ass4_12CS10006.o y.tab.o lex.yy.o
	cc ass4_12CS10006.o y.tab.o lex.yy.o -lfl
y.tab.o: y.tab.c
	cc -c y.tab.c
y.tab.c: ass4_12CS10006.y
	yacc -dtv ass4_12CS10006.y
lex.yy.o: lex.yy.c y.tab.o
	cc -c lex.yy.c
lex.yy.c: ass4_12CS10006.l 
	flex ass4_12CS10006.l
ass4_12CS10006.o: ass4_12CS10006.c 
	cc -c ass4_12CS10006.c 
clean:
	rm lex.yy.c lex.yy.o a.out y.tab.o y.tab.c ass4_12CS10006.o y.tab.h y.output
