%{
    #include "y.tab.h"
%}
%%
a|A   {return A;}     //Rule for char a or A 
b|B   {return B;}     //Rule for char b or B
[\n]  {return '\n';}  //Rule for new line
%%