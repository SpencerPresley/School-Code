/* 

LEXER for TINY.Y 

I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Spencer Presley

*/

%option yylineno
%option noyywrap

%{
	#define DEBUG 1
	typedef YYTOKENTYPE Token;
	Token scanned(Token t);
%}

NUM [0-9]+
ID [a-zA-Z][0-9a-zA-Z]*
%%


"ERROR" { return scanned(ERROR); } /* to recognize "ERROR" from tiny.y, "error" handled by yyerror */
<<EOF>> { return scanned(ENDFILE); } /* for EOF. Both together are to handle %token ENDFILE ERROR in tiny.y */

if { return scanned(IF); } /* Start of second %token in tiny.y */
then { return scanned(THEN); }
else { return scanned(ELSE); }
end { return scanned(END); }
repeat { return scanned(REPEAT); }
until { return scanned(UNTIL); }
read { return scanned(READ); }
write { return scanned(WRITE); } /* Done second %token in tiny.y */

{ID} { return scanned(ID); } /* Start %token ID NUM in tiny.y, this is specifically the 'ID' part */
{NUM} { return scanned(NUM); } /* This is specifically the 'NUM' part. Done %token ID NUM from tiny.y */

":=" { return scanned(ASSIGN); } /*Start 4th %token from tiny.y. If lexer sees := recognizes it as assignment operator, return token ASSIGN to parser */
"==" { return scanned(EQ); } /* If lexer sees == recognizes it as equal operator, return token EQ to parser */
"<" { return scanned(LT); } /* If lexer sees < recognizes it as less than operator, returns token LT to parser */
"+" { return scanned(PLUS); } /* If lexer sees + recognizes it as plus operator, returns token PLUS to parser */
"-" { return scanned(MINUS); } /* If lexer sees - recognizes it as minus operator, returns token MINUS to parser */
"*" { return scanned(TIMES); } /* If lexer sees * recognizes it as multiplication operator, returns TIMES to parser */
">" { return scanned(OVER); } /* If lexer sees > recongnizes it as over operator ( greater than ), returns OVER to parser */
"(" { return scanned(LPAREN); } /* If lexer sees ( recognizes it as a left parenthesis, returns LPAREN to parser */
")" { return scanned(RPAREN); } /* If lexer sees ) recognizes it as a right parenthesis, returns RPAREN to parser */
";" { return scanned(SEMI); } /* If lexer sees ; recognizes it as a semi colon, returns SEMI to parser. DONE 4th %token from tiny.y */

"{" { /* used to ignore comments in .y file as shown in example output of project1-1.pdf */
        char curr; /* declaring char variable. curr short for current. As in curr will store current character*/
        curr = input(); /* using built in 'input()' function to assign the character to curr */
        while( curr != '}' )
        {
            if(curr == EOF) break; /* checks that it isn't EOF, if it is break out of while loop */
            curr = input(); /* assigns new input character to curr ( current character ) */
        }
    }
"//" { /* to ignore comments indicated with // */ }
"/*" { /* to ignore comments made the /star way */ 
        char curr; /* same logic as "{" so won't go through everything unless it's new */
        while(1) /* run until break */
        {
            curr = input(); /* assign input() to curr each iteration */
            if(curr == '*') /* checking if curr = * character so can check if it's followed by / character indicating EO comment */
            {
                char next = input(); /* used to check what next character is */
                if(next == '/') /* if the next character is in face / then we have star/ indicating EO comment and we break */
                    break;
            }
        }
    }


    
%%

/* process and return scanned token t */
Token scanned (Token t)
{
	if(DEBUG == 0) return t;
	
	switch(t)
	{
		case ERROR: printf("Error "); return t;
		case ENDFILE: printf("ENDFILE\n"); return t;
		case IF: printf("IF "); return t;
		case THEN: printf("THEN "); return t;
		case ELSE: printf("ELSE "); return t;
		case END: printf("END "); return t;
		case REPEAT: printf("REPEAT "); return t;
		case UNTIL: printf("UNTIL "); return t;
		case READ: printf("READ "); return t;
		case WRITE: printf("WRITE "); return t;
		case ID: printf("ID(%s) ", yytext); return t;
		case NUM: printf("NUM(%s) ", yytext); return t;
		case ASSIGN: printf("ASSIGN "); return t;
		case EQ: printf("EQ "); return t;
		case LT: printf("LT "); return t;
		case PLUS: printf("PLUS "); return t;
		case MINUS: printf("MINUS "); return t;
		case TIMES: printf("TIMES "); return t;
		case OVER: printf("OVER "); return t;
		case LPAREN: printf("LPAREN "); return t;
		case RPAREN: printf("RPAREN "); return t;
		case SEMI: printf("SEMI "); return t;
		default: printf("ERROR: invalid token in scanned().\n"); exit (-1);
	}

}
