lex icg.l
yacc -d icg.y -w
g++ y.tab.c -ll -ly -w
./a.out>out.txt
python3 icg_manipulate.py out.txt > final_icg.txt
