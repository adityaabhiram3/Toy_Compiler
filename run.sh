cd AST
lex ast.l
yacc -d ast.y -w
g++ lex.yy.c y.tab.c -ll -ly -w
./a.out<../ICG/input.cpp
cd ..


cd ICG
lex icg.l
yacc -d icg.y -w
g++ y.tab.c -ll -ly -w
./a.out<input.cpp>out.txt
python3 icg_manipulate.py > final_icg.txt
cd ..

cd co
python3 code_opt.py ../ICG/final_icg.txt > oc.txt
cd ..

cd assembly
python3 assembly.py ../co/oc.txt > result.txt
cd ..
