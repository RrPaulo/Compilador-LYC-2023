flex Lexico.l
bison Sintactico.y
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c -o Exec
Exec prueba.txt