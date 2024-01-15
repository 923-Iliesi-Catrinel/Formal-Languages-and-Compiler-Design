%{
#include <stdio.h>
#include <stdlib.h>

int yyerror(const char *s);

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


%%

constant : INTCONSTANT      { printf("constant -> intconstant\n"); }
         | CHARCONSTANT     { printf("constant -> charconstant\n"); }
         | STRINGCONSTANT   { printf("constant -> stringconstant\n"); }
         ;

/*var : IDENTIFIER { printf("var -> identifier\n"); }
    | IDENTIFIER SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE { printf("var -> identifier [ expression ]\n"); }
    ;

value : constant { printf("value -> constant\n"); }
      | var      { printf("value -> var\n"); }
      ;

newline : "\\r\\n"  { printf("newline -> \\r\\n\n"); }
        | "\\n"     { printf("newline -> \\n\n"); }
        ;

newlines : newline            { printf("newlines -> newline\n"); }
         | newline newlines   { printf("newlines -> newline newlines\n"); }
         ;

stmtlist : stmt                       { printf("stmtlist -> stmt\n"); }
         | stmt newlines stmtlist     { printf("stmtlist -> stmt newlines stmtlist\n"); }
         ;

program : stmtlist  { printf("program -> stmtlist\n"); }
        ;

stmt : simplstmt            { printf("stmt -> simplstmt\n"); }
     | structstmt           { printf("stmt -> structstmt\n"); }
     ;

simplstmt : decllist        { printf("stmt -> decllist\n"); }
          | assignstmt      { printf("stmt -> assignstmt\n"); }
          | iostmt          { printf("stmt -> iostmt\n"); }
          ;

decllist : declaration                      { printf("decllist -> declaration\n"); }
         | declaration newlines decllist    { printf("decllist -> declaration newlines decllist\n"); }
         | declaration COMMA decllist       { printf("decllist -> declaration , decllist\n"); }
         ;

declaration : IDENTIFIER COLON type               { printf("declaration -> IDENTIFIER : type\n"); }
            | IDENTIFIER COLON type EQ expression { printf("declaration -> IDENTIFIER : type = expression\n"); }
            ;

type : primitive_type                { printf("type -> primitive_type\n"); }
     | arraydecl                     { printf("type -> arraydecl\n"); }
     ;

primitive_type : INTEGER             { printf("primitive_type -> integer\n"); }
               | BOOLEAN             { printf("primitive_type -> boolean\n"); }
               | CHARACTER           { printf("primitive_type -> character\n"); }
               | STRING              { printf("primitive_type -> string\n"); }
               ;

arraydecl : IDENTIFIER COLON ARRAY PARENTHESIS_OPEN primitive_type PARENTHESIS_CLOSE SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE { printf("arraydecl -> identifier : array (primitive_type) [expression]"); }
          ;

assignstmt : IDENTIFIER ARROW expression { printf("assignstmt -> IDENTIFIER -> expression\n"); }
           ;

expression : term                         { printf("expression -> term\n"); }
           | expression ADD term          { printf("expression -> expression ADD term\n"); }
           | expression SUB term          { printf("expression -> expression SUB term\n"); }
           ;

term : factor                { printf("term -> factor\n"); }
     | term MUL factor       { printf("term -> term MUL factor\n"); }
     | term DIV factor       { printf("term -> term DIV factor\n"); }
     | term MOD factor       { printf("term -> term MOD factor\n"); }
     ;

factor : SQUAREBRACKET_OPEN expression SQUAREBRACKET_CLOSE  { printf("factor -> [ expression ]\n"); }
       | value                                              { printf("factor -> value\n"); }
       ;

readstmt : READ SQUAREBRACKET_OPEN IDENTIFIER SQUAREBRACKET_CLOSE { printf("readstmt -> read [ IDENTIFIER ]\n"); }
         ;

writestmt : WRITE SQUAREBRACKET_OPEN IDENTIFIER SQUAREBRACKET_CLOSE     { printf("writestmt -> write [ IDENTIFIER ]\n"); }
          | WRITE SQUAREBRACKET_OPEN STRINGCONSTANT SQUAREBRACKET_CLOSE { printf("writestmt -> write [ STRINGCONSTANT ]\n"); }
          ;

iostmt : readstmt  { printf("iostmt -> readstmt\n"); }
       | writestmt { printf("iostmt -> writestmt\n"); }
       ;

structstmt : ifstmt           { printf("structstmt -> ifstmt\n"); }
           | whilestmt        { printf("structstmt -> whilestmt\n"); }
           | forstmt          { printf("structstmt -> forstmt\n"); }
           ;

cmpstmt : CURLYBRACKET_OPEN stmtlist CURLYBRACKET_CLOSE { printf("cmpstmt -> { stmtlist }\n"); }
        ;

ifstmt : IF SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt                          { printf("ifstmt -> if [ conditions ] cmpstmt \n"); }
       | IF SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt OTHERWISE cmpstmt { printf("ifstmt -> if [ conditions ] { cmpstmt } otherwise cmpstmt\n"); }
       ;

whilestmt : LOOPWHILE SQUAREBRACKET_OPEN conditions SQUAREBRACKET_CLOSE cmpstmt { printf("whilestmt -> while [ conditions ] cmpstmt\n"); }
          ;

forstmt : LOOPFOR SQUAREBRACKET_OPEN assignstmt COMMA conditions COMMA assignstmt SQUAREBRACKET_CLOSE cmpstmt { printf("forstmt -> for [assignstmt, conditions, assignstmt] cmpstmt \n"); }
        ;

condition : expression RELATION expression      { printf("condition -> expression RELATION expression\n"); }
          ;

conditions : condition                          { printf("conditions -> condition\n"); }
           | condition AND conditions           { printf("conditions -> condition and conditions\n"); }
           | condition OR conditions            { printf("conditions -> condition or conditions\n"); }
           ;

RELATION : GE           { printf("RELATION -> >=\n"); }
         | LE           { printf("RELATION -> <=\n"); }
         | GT           { printf("RELATION -> >\n"); }
         | LT           { printf("RELATION -> <\n"); }
         | EQ           { printf("RELATION -> =\n"); }
         | NEQ          { printf("RELATION -> !=\n"); }
         | AND          { printf("RELATION -> &&\n"); }
         | OR           { printf("RELATION -> ||\n"); }
         ;*/

%%

int yyerror(const char *s) {
    printf("%s\n", s);
    return 0;
}

extern FILE *yyin;

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Error opening file %s\n", argv[1]);
            exit(1);
        }
    }

    if (!yyparse()) {
        fprintf(stderr, "\tOK\n");
    }
}
