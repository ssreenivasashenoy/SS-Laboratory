%{
    #include<stdio.h>
    int id=0,flag=0,op=0,plus=0,min=0,mul=0,div=0,b=0;
%}
%%
[0-9a-zA-Z]+  {id++;printf("\nIdentifier: ");ECHO;}      //Rule for identifiers
[+]           {op++;plus++;printf("\nOperator: ");ECHO;} //Rule for addition operator
[-]           {op++;min++;printf("\nOperator: ");ECHO;}  //Rule for subtraction operator
[*]           {op++;mul++;printf("\nOperator: ");ECHO;}  //Rule for multiplication operator
[/]           {op++;div++;printf("\nOperator: ");ECHO;}  //Rule for division operator
"("           {b++;}                                     //Rule for open braces
")"           {b--;}                                     //Rule for close braces
.             {flag=1;}                                  //Rule for any other characters
\n            {;}                                        //Rule for new line
%%
int main(){
    printf("Enter Expression: ");
    yylex();
    if((op+1)==id && b==0 && flag==0){
        printf("Valid Expression!\n");
        printf("Number of identifiers: %d\n",id);
        printf("Number of operators: %d\n",op);
        printf("Number of Addition operators: %d\n",plus);
        printf("Number of Subtraction operators: %d\n",minus);
        printf("Number of Multiplication operators: %d\n",mul);
        printf("Number of Division operators: %d\n",div);
    }
    else{
        printf("Invalid Expression!\n");
    }
    return 0;
}