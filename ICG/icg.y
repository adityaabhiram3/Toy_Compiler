%{
  #include <iostream>
  using namespace std;
  #include<stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  int top=-1;
  void yyerror(char *);
extern "C"{
        int yyparse(void);
        int yylex(void);  
        int yywrap()
        {
                return 1;
        }
}
  extern FILE *yyin;
  #define YYSTYPE char*
void if1();
void for1();
void for2();
void for3();
void for4();
void while1();
void while2();
void while3();
void if3();
void push();
void pushab();
void ifelse1();
void ifelse2();
void ifelse3();
void ternary1();
void ternary2();
void ternary3();
void pusha();
void codegen_assigna();
void codegen();
void codegen_assign();
void pushx();
%}

%start S
%token ID NUM T_lt T_gt T_lteq T_gteq T_neq T_noteq T_eqeq T_and T_or T_incr T_decr T_not T_eq WHILE INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE COUT STRING FOR ENDL T_ques T_colon FLOATS

%token T_pl T_min T_mul T_div
%left T_lt T_gt
%left T_pl T_min
%left T_mul T_div

%%
S
      : START 
      ;

START
      : INCLUDE T_lt H T_gt MAIN
      | INCLUDE "\"" H "\"" MAIN
      ;

MAIN
      : VOID MAINTOK BODY
      | INT MAINTOK BODY
      ;

BODY
      : '{' C '}'
      ;

C
      : C statement ';'
      | C LOOPS
      | statement ';'
      | LOOPS
      ;

LOOPS
      : WHILE {while1();} '(' COND ')'{while2();} LOOPBODY{while3();}
      | FOR '(' ASSIGN_EXPR{for1();} ';' COND{for2();} ';' statement{for3();} ')' LOOPBODY{for4();}		
      | IF '(' COND ')' {ifelse1();} LOOPBODY{ifelse2();} else
      
      ;
else: ELSE LOOPBODY{ifelse3();} 
      | 
;

TERNARY_EXPR
      :  '(' TERNARY_COND ')' {ternary1();} T_ques statement{ternary2();} T_colon statement{ternary3();}
      ;

LOOPBODY
  	  : '{' LOOPC '}'
  	  | ';'
  	  | statement ';'
  	  ;

LOOPC
      : LOOPC statement ';'
      | LOOPC LOOPS
      | statement ';'
      | LOOPS
      ;

statement
      : ASSIGN_EXPR
      | EXP
      | TERNARY_EXPR
      | PRINT
      ;

TERNARY_COND  : T_B {codegen_assigna();}
              | T_B T_and{codegen_assigna();} TERNARY_COND
              | T_B {codegen_assigna();}T_or TERNARY_COND
              | T_not T_B{codegen_assigna();}
              ;

T_B : T_V RELOP{push();} LIT
  |'(' T_B ')'
  | T_V {pushab();}
  ;


COND  : B {codegen_assigna();}
      | B T_and{codegen_assigna();} COND
      | B {codegen_assigna();}T_or COND
      | T_not B{codegen_assigna();}
      ;

B : V RELOP{push();}LIT
  |'(' B ')'
  | V {pushab();}
  ;

F :T_eq{push();}LIT
  |LIT{pusha();}
  ;

V : ID{push();}

T_V : ID{pushx();}

ASSIGN_EXPR
      : LIT {push();} T_eq {push();} EXP {codegen_assign();}
      | TYPE LIT {push();} T_eq {push();} EXP {codegen_assign();}
      ;

EXP
	  : ADDSUB
	  | EXP T_lt {push();} ADDSUB {codegen();}
	  | EXP T_gt {push();} ADDSUB {codegen();}
	  ;

ADDSUB
      : TERM
      | EXP T_pl {push();} TERM {codegen();}
      | EXP T_min {push();} TERM {codegen();}
      ;

TERM
	  : FACTOR
      | TERM T_mul {push();} FACTOR {codegen();}
      | TERM T_div {push();} FACTOR {codegen();}
      ;

FACTOR
	  : LIT
	  | '(' EXP ')'
  	;

PRINT
      : COUT T_lt T_lt a
      ;
a:     STRING T_lt T_lt a |  STRING
      ;
LIT
      : ID {push();}
      | NUM {push();}
      | FLOATS {push();}
      | STRING {push();}
      ;
TYPE
      : INT
      | CHAR
      | FLOAT
      ;
RELOP
      : T_lt
      | T_gt
      | T_lteq
      | T_gteq
      | T_neq
      | T_eqeq
      ;
bin_boolop
      : T_and
      | T_or
      ;

un_arop
      : T_incr
      | T_decr
      ;

un_boolop
      : T_not
      ;


%%

#include "lex.yy.c"
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_for=0;
int flag_set = 1;

int main(int argc,char *argv[])
{

  yyin = fopen(argv[1],"r");
  if(!yyparse()) 
  {
    //successful
  }
  else
  {
    cout<<"Parsing failed\n";
  }

  fclose(yyin);
  return 0;
}

void yyerror(char *s)
{
 cout<<"Error at "<<yylineno<<"\n";
}

void push()
{
strcpy(st[++top],yytext);
}
void pusha()
{
strcpy(st[++top],"  ");
}
void pushx()
{
strcpy(st[++top],"x ");
}
void pushab()
{
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
}
void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    cout<<temp<<"="<<st[top-2]<<" "<<st[top-1]<<" "<<st[top]<<"\n";
    top-=2;
    strcpy(st[top],temp);

temp_i++;
}
void codegen_assigna()
{
strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
strcat(temp,tmp_i);
cout<<temp<<"="<<" " <<st[top-2]<<" "<<st[top-1]<<" "<<st[top]<<"\n";
if(strlen(st[top])==1)
{
    char t[20];
	strcpy(t,st[top-2]);
	strcat(t,st[top-1]);
	
    
}

top-=4;

temp_i++;
strcpy(st[++top],temp);
}

void codegen_umin()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    cout<<temp<<"= -"<<st[top]<<"\n";
    top--;
    strcpy(st[top],temp);
    temp_i++;
}
void codegen_assign()
{
    cout<<st[top-3]<<"="<<st[top]<<"\n";
    top-=2;
}

void if1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 cout<<temp<<"= not "<<st[top]<<"\n";
 cout<<"if "<<temp<<" goto L"<<lnum<<"\n";
 temp_i++;
 label[++ltop]=lnum;
}

void if3()
{
    int y;
    y=label[ltop--];
    cout<<"L"<<y<<"\n";
}

void ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    cout<<temp<<"= not "<<st[top]<<"\n";
    cout<<"if "<<temp<<" goto L"<<lnum<<"\n";
    temp_i++;
    label[++ltop]=lnum;
}

void ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    cout<<"goto L"<<lnum<<"\n";
    cout<<"L"<<x<<"\n";
    label[++ltop]=lnum;
}

void ifelse3()
{
int y;
y=label[ltop--];
 cout<<"L"<<y<<"\n";
lnum++;
}

void ternary1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
    cout<<temp<<"= not "<<st[top]<<"\n";
    cout<<"if "<<temp<<" goto L"<<lnum<<"\n";
 temp_i++;
 label[++ltop]=lnum;
}

void ternary2()
{
int x;
lnum++;
x=label[ltop--];
 cout<<"goto L"<<lnum<<"\n";
 cout<<"L"<<x<<"\n";
    label[++ltop]=lnum;
}

void ternary3()
{
int y;
y=label[ltop--];
 cout<<"L"<<y<<"\n";
lnum++;
}

void while1()
{

 l_while = lnum;
 cout<<"L"<<lnum++<<"\n";
}

void while2()
{
 strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 cout<<temp<<"= not "<<st[top]<<"\n";
 cout<<"if "<<temp<<" goto L"<<lnum<<"\n";
temp_i++;
 }

void while3()
{
cout<<"goto L"<<l_while<<"\n";
 cout<<"L"<<lnum++<<"\n";
}

void for1()
{
 l_for = lnum;
 cout<<"L"<<lnum++<<"\n";
}
void for2()
{
    strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
    cout<<temp<<"= not "<<st[top]<<"\n";
    cout<<"if "<<temp<<" goto L"<<lnum<<"\n";
    label[++ltop]=lnum;
    lnum++;
temp_i++;
    cout<<"goto L"<<lnum<<"\n";
    label[++ltop]=lnum;
    cout<<"L"<<++lnum<<":\n";
 }
void for3()
{
    int x;
    x=label[ltop--];
    cout<<"goto L"<<l_for<<"\n";
    cout<<"L"<<x<<":\n";
}

void for4()
{
    int x;
    x=label[ltop--];
    cout<<"goto L"<<lnum<<"\n";
    cout<<"L"<<x<<":\n";
}
