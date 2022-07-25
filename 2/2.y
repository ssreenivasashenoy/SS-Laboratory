%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token A B
%%
input : S '\n' {printf("Successful Grammar");exit(0);}
    S : A S1 B|B
    S1 : ;|A S1 ;
%%
int yyerror(){
    printf("ERROR!");
    exit(0);
}
int main(){
    printf("Enter String: ");
    yyparse();
}