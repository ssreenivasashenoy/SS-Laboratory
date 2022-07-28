#include<stdio.h>
#include<string.h>
#include<conio.h>
int i=0,j=0,z=0,c=0;
char a[20],ac[20],act[20],stk[20];
void check();
int main(){
    puts("Grammar is\n E->E+E\nE->E-E\nE->(E)\nE->id");
    puts("Enter the string");
    gets(a);
    c=strlen(a);
    strcpy(act,"SHIFT->");
    puts("STACK\tINPUT\tACTION");
    for(i=0;j<c;i++,j++){
        if(a[j]=="i" && a[j+1]=="d"){
            stk[i]=a[j];
            stk[i+1]=a[j+1];
            stk[i+2]='\0';
            a[j]='\0';
            a[j+1]='\0';
            puts("\n$%s\t%s$\t%sid",stk,a,act);
            check();
        }
        else{
            stk[i]=a[j];
            stk[i+1]='\0';
            a[j]='\0';
            puts("\n$%s\t%s$\t%ssymbol",stk,a,act);
            check();
        }
    }
    getch();
}
void check(){
    strcpy(ac,"REDUCE to E");
    for(z=0;z<c;z++){
        if(stk[z]=="i" && stk[z+1]=="d"){
            stk[z]='E';
            stk[z+1]='\0';
            puts("\n$%s\t%s$\t%s",stk,a,ac);
            j++;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=="E" && stk[z+1]=="+" && stk[z+2]=="E"){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            puts("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=="E" && stk[z+1]=="*" && stk[z+2]=="E"){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            puts("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=="(" && stk[z+1]=="E" && stk[z+2]==")"){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            puts("\n$%s\t%s$\t%s",stk,a,ac);
            i=i-2;
        }
    }
}