all: gen
gen: a.exe
	a.exe < sample_input1.c
a.exe: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c
y.tab.c: parser.y
	bison -dy parser.y
lex.yy.c: lexer.l
	flex lexer.l
clean: