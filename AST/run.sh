lex ast.l
yacc -d ast.y -w
g++ lex.yy.c y.tab.c -ll -ly -w
