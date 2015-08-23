a.out:  ass5_12CS10006_translator.o y.tab.o lex.yy.o 
	g++ -w ass5_12CS10006_translator.o y.tab.o lex.yy.o -lfl
y.tab.o: y.tab.c
	g++ -w -c y.tab.c
y.tab.c: ass5_12CS10006.y ass5_12CS10006_translator.h 
	yacc -dtv ass5_12CS10006.y
lex.yy.o: lex.yy.c 
	g++ -w -c lex.yy.c 
lex.yy.c: ass5_12CS10006.l y.tab.c 
	flex ass5_12CS10006.l 
ass5_12CS10006_translator.o: ass5_12CS10006_translator.cxx ass5_12CS10006_translator.h
	g++ -w -c ass5_12CS10006_translator.cxx
clean:
	rm lex.yy.c lex.yy.o a.out y.tab.o y.tab.c ass5_12CS10006_translator.o y.tab.h y.output ass5_12CS10006_quads1.out ass5_12CS10006_quads2.out ass5_12CS10006_quads3.out ass5_12CS10006_quads4.out ass5_12CS10006_quads5.out ass5_12CS10006_result1.c ass5_12CS10006_result2.c ass5_12CS10006_result3.c ass5_12CS10006_result4.c ass5_12CS10006_result5.c



