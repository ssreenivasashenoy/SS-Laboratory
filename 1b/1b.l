%{
    #include "y.tab.h"
    extern yylval;
%}
%%
[0-9]+       {yylval=atoi(yytext);return num;} //ASCII to integer conversion
[\+\-\*\/]   {return yytext[0];}               //Rule for operators
[(]          {return yytext[0];}               //Rule for open braces
[)]          {return yytext[0];}               //Rule for close braces
[;]          {;}                               //Rule for end of statement
\n           {return 0;}                       //Rule for new line
%%