# Variables to control Makefile operation
CXX = g++
YACC = yacc
LEX = lex

# Targets
all: proiect

proiect: lex.yy.c y.tab.c
	$(CXX) lex.yy.c y.tab.c -ll -o proiect

y.tab.c y.tab.h: proiect.y
	$(YACC) -d proiect.y

lex.yy.c: proiect.l y.tab.h
	$(LEX) proiect.l

clean: 
	rm -f lex.yy.c y.tab.c y.tab.h proiect



