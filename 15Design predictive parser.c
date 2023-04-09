//input id*id output valid
//input "id"*"id" output invalid
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char ch;
#define id 0
#define CONST 1
#define mulop 2
#define addop 3
#define op 4
#define cp 5
#define err 6
#define col 7
#define size 50
int token;
char lexbuff[size];
int lookahead=0;
int main() {
 //clrscr();
 printf(" Enter the string :");
 gets(lexbuff);
 parser();
 return 0; }
parser() {
if(E())
printf("valid string");
else
printf("invalid string");
getch();
return 0; }
E() {
if(T()) {
 if(EPRIME())
return 1;
 else
 return 0;

}
 else
 return 0; }
T() {
 if(F())

{
 if(TPRIME())
 return 1;
 else
 return 0;

}
 else
 return 0; }
EPRIME() {
 token=lexer();
 if(token==addop)

{
 lookahead++;
 if(T())

{
 if(EPRIME())
 return 1;
 else
 return 0;

}
 else
 return 0;

}
else
 return 1;
 }
TPRIME() {
 token=lexer();
 if(token==mulop)

{
 lookahead++;
 if(F())

{
 if(TPRIME())
 return 1;
 else
 return 0;

}
 else
return 0;

}
 else
return 1;
}
F() {
 token=lexer();
 if(token==id)
 return 1;
 else

{
 if(token==4)

{
 if(E())

{
if(token==5)
 return 1;
else
return 0;

}
 else
 return 0;

}
 else
 return 0; }}
lexer() {
 if(lexbuff[lookahead]!='\n')

{
 while(lexbuff[lookahead]=='\t')
 lookahead++;
 if(isalpha(lexbuff[lookahead]))

{
 while(isalnum(lexbuff[lookahead]))
 lookahead++;
 return(id);

}
 else

{
 if(isdigit(lexbuff[lookahead]))

{
while(isdigit(lexbuff[lookahead]))
lookahead++;
return CONST;

}
 else

{
 if(lexbuff[lookahead]=='+')

{
return(addop);

}
 else

{
if(lexbuff[lookahead]=='*') {
 return(mulop); }
else {
 if(lexbuff[lookahead]=='(')

{
 lookahead++;
 return(op);

}
 else
 {
 if(lexbuff[lookahead]==')')
 {
 return(op);
 }
 else
 {
 return(err);
 }
 }
 }
 }
}
 }
 }
 else
 return (col);
 }
