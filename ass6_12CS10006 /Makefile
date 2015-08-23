a.out:  ass6_12CS10006_target_translator.o ass6_12CS10006_translator.o y.tab.o lex.yy.o 
	 g++ -w ass6_12CS10006_target_translator.o ass6_12CS10006_translator.o y.tab.o lex.yy.o  -lfl 
ass6_12CS10006_target_translator.o:   ass6_12CS10006_target_translator.cxx
	g++ -w -c ass6_12CS10006_target_translator.cxx	
y.tab.o: y.tab.c
	g++ -w -c y.tab.c
y.tab.c: ass6_12CS10006.y ass6_12CS10006_translator.h 
	yacc -dtv ass6_12CS10006.y
lex.yy.o: lex.yy.c 
	g++ -w -c lex.yy.c 
lex.yy.c: ass6_12CS10006.l y.tab.c 
	flex ass6_12CS10006.l 
ass6_12CS10006_translator.o: ass6_12CS10006_translator.cxx ass6_12CS10006_translator.h
	g++ -w -c ass6_12CS10006_translator.cxx
clean:
	rm *.out *.s *tokens* ass6_12CS10006_target_translator.o ass6_12CS10006_translator.o lex.yy.c lex.yy.o y.tab.o y.tab.c y.tab.h y.output  
Test: 
	cc -m32 -o test.out ass6_12CS10006_test.s -L. libass6_12CS10006.a
