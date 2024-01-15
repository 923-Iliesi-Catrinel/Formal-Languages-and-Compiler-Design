%{
#include <stdio.h>
#include <stdlib.h>

#include "cat.h"

void yyerror(const char *s);

#define YYDEBUG 1
%}

%token READ;
%token WRITE;
%token IF;
%token OTHERWISE;
%token LOOPWHILE;
%token LOOPFOR;
%token INTEGER;
%token BOOLEAN;
%token CHARACTER;
%token ARRAY;
%token STRING;

%token ARROW;
%token ADD;
%token SUB;
%token MUL;
%token DIV;
%token MOD;
%token LT;
%token LE;
%token EQ;
%token NEQ;
%token GE;
%token GT;
%token AND;
%token OR;

%token IDENTIFIER;
%token INTCONSTANT;
%token CHARCONSTANT;
%token STRINGCONSTANT;

%token SQUAREBRACKET_OPEN;
%token SQUAREBRACKET_CLOSE;
%token CURLYBRACKET_OPEN;
%token CURLYBRACKET_CLOSE;
%token PARENTHESIS_OPEN;
%token PARENTHESIS_CLOSE;
%token COMMA;
%token COLON;
%token SEMICOLON;

%start program

%%

constant : INTCONSTANT      { printf("constant -> intconstant\n"); }
         | CHARCONSTANT     { printf("constant -> charconstant\n"); }
         | STRINGCONSTANT   { printf("constant -> stringconstant\n"); }
         ;

var : IDENTIFIER op_arr { printf("Variable -> IDENTIFIER OptionalArray\n"); }
    ;

op_arr : SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE      { printf("op_arr -> [ expression ]\n"); }
       |                                                        { printf("op_arr -> epsilon\n"); }
       ;

value : constant { printf("value -> constant\n"); }
      | var      { printf("value -> var\n"); }
      ;

program : stmtlist  { printf("program -> stmtlist\n"); }
        ;

declaration : type op_assign { printf("declaration -> type op_assign\n"); }
            ;

op_assign : ARROW expression { printf("op_assign -> -> expression\n"); }
          |                  { printf("op_assign -> epsilon\n"); }
          ;

stmtlist : stmt SEMICOLON stmtlisttail { printf("stmtlist -> stmt ; stmtlisttail\n"); }
         ;

stmtlisttail : stmtlist { printf("stmtlist -> stmtlist\n"); }
             |          { printf("stmtlist -> epsilon\n"); }
             ;

stmt : IDENTIFIER stmttail { printf("stmt -> IDENTIFIER stmttail\n"); }
     | iostmt              { printf("stmt -> iostmt\n"); }
     | ifstmt              { printf("stmt -> ifstmt\n"); }
     | whilestmt           { printf("stmt -> whilestmt\n"); }
     | forstmt             { printf("stmt -> forstmt\n"); }
     ;

stmttail: COLON declaration               { printf("stmttail -> : declaration\n"); }
             | op_arr ARROW expression { printf("stmttail -> op_arr -> expression\n"); }
             ;

type : primitive_type                { printf("type -> primitive_type\n"); }
     | arraydecl                     { printf("type -> arraydecl\n"); }
     ;

primitive_type : INTEGER             { printf("primitive_type -> integer\n"); }
               | BOOLEAN             { printf("primitive_type -> boolean\n"); }
               | CHARACTER           { printf("primitive_type -> character\n"); }
               | STRING              { printf("primitive_type -> string\n"); }
               ;

arraydecl : ARRAY PARENTHESIS_OPEN primitive_type PARENTHESIS_CLOSE SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE { printf("arraydecl -> identifier : array (primitive_type) [expression]"); }
          ;

cmpstmt : CURLYBRACKET_OPEN stmtlist CURLYBRACKET_CLOSE { printf("cmpstmt -> { stmtlist }\n"); }
        ;

expression : term expressiontail { printf("expression -> term expressiontail\n"); }
          ;

expressiontail: ADD term expressiontail  { printf("expressiontail -> ADD term expressiontail\n"); }
              | SUB term expressiontail  { printf("expressiontail -> SUB term expressiontail\n"); }
              |             { printf("expressiontail -> epsilon\n"); }
              ;

factor: SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE { printf("factor -> [ Expression ]\n"); }
      | value                                             { printf("factor -> value\n"); }
      ;

term : factor termtail { printf("term -> factor termtail\n"); }
     ;

termtail: MUL factor termtail  { printf("termtail -> MUL factor termtail\n"); }
        | DIV factor termtail { printf("termtail -> DIV factor termtail\n"); }
        | MOD factor termtail { printf("termtail -> MOD factor termtail\n"); }
        |                     { printf("termtail -> epsilon\n"); }
        ;

iostmt : readstmt  { printf("iostmt -> readstmt\n"); }
       | writestmt { printf("iostmt -> writestmt\n"); }
       ;

readstmt : READ SQUAREBRACKET_OPEN IDENTIFIER SQUAREBRACKET_CLOSE { printf("readstmt -> read [ IDENTIFIER ]\n"); }
         ;

writestmt : WRITE SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE     { printf("writestmt -> write [ IDENTIFIER ]\n"); }
          ;

ifstmt : IF SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt elsestmt                         { printf("ifstmt -> if [ conditions ] cmpstmt \n"); }
       ;

elsestmt : OTHERWISE cmpstmt { printf("elsestmt -> OTHERWISE cmpstmt\n"); }
         |             { printf("elsestmt -> epsilon\n"); }
         ;

whilestmt : LOOPWHILE SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt { printf("whilestmt -> while [ conditions ] cmpstmt\n"); }
          ;

assignstmt : IDENTIFIER ARROW expression { printf("assignstmt -> IDENTIFIER -> expression\n"); }
           ;

forstmt : LOOPFOR SQUAREBRACKET_OPEN assignstmt COMMA conditions COMMA assignstmt SQUAREBRACKET_CLOSE cmpstmt { printf("forstmt -> for [assignstmt, conditions, assignstmt] cmpstmt \n"); }
        ;

condition: simplecondition conditiontail { printf("condition -> simplecondition conditiontail\n"); }
         ;

conditiontail: AND simplecondition conditiontail { printf("conditiontail -> AND simplecondition conditionTail\n"); }
             | /* empty */                       { printf("conditiontail -> epsilon\n"); }
             ;

simplecondition: expression RELATION expression { printf("simplecondition -> expression Relation expression\n"); }
               ;

conditions: condition conditionstail { printf("conditions -> condition conditiontail\n"); }
          ;

conditionstail: OR condition conditionstail { printf("conditionstail -> OR condition conditionstail\n"); }
              |                             { printf("conditionstail -> epsilon\n"); }
              ;

RELATION : GE           { printf("RELATION -> >=\n"); }
         | LE           { printf("RELATION -> <=\n"); }
         | GT           { printf("RELATION -> >\n"); }
         | LT           { printf("RELATION -> <\n"); }
         | EQ           { printf("RELATION -> =\n"); }
         | NEQ          { printf("RELATION -> !=\n"); }
         | AND          { printf("RELATION -> &&\n"); }
         | OR           { printf("RELATION -> ||\n"); }
         ;

%%

extern FILE *yyin;
extern int yyparse(void);

void yyerror(const char *s) {
    printf("Parser error: %s\n", s);

    fclose(yyin);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc > 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Error: Could not open file %s\n", argv[1]);
            exit(1);
        }
    } else {
        yyin = stdin;
    }

    yyparse();
    fclose(yyin);
    return 0;
}
