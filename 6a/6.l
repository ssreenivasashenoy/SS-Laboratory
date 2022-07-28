%{
    #include<stdio.h>
    #include<stdlib.h>
    int sl=0,ml=0;
%}
%%
"/*" [0-9a-zA-z''\t\n]+ "*/" ml++;
"//".* sl++;
%%
int main(int argc,char **argv){
    if(argc<3){
        printf("Enter the input and output files:")
        exit(0);
    }
    yyin=fopen(argv[1],"r");
    if(!yyin){
        printf("File not found");
        exit(1);
    }
    yyout=fopen(argv[2],"w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    printf("Number of single line comments : %d\n",sl);
    printf("Number of single line comments : %d",ml);
    return 0;
}