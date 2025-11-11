#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define n 100
char stack[n];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==n-1;
}
void push(char c){
    if (!isFull())
        stack[++top]=c;
}
char pop(){
    if(!isEmpty())
        return stack[top--];
    return '\0';
}
char peek(){
    if(!isEmpty())
        return stack[top];
    return '\0';
}
int precedence(char op){
    if(op=='^')return 3;
    if(op=='*'||op=='/')return 2;
    if(op=='+'||op=='-')return 1;
    return 0;
}
void reverse(char str[]){
    int i,j;
    char temp;
    for(i=0,j=strlen(str)-1;i<j;i++,j--){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
void infixToPostfix(char infix[],char postfix[]){
    int i,j;
    i=0;
    j=0;
    while(infix[i]!='\0'){
        char s=infix[i];
        if(isalnum(s)){
            postfix[j++]=s;
        }
        else if(s=='('){
            push(s);
        }
        else if(s==')'){
            while(!isEmpty()&&peek()!='('){
                postfix[j++]=pop();
            }
            if(!isEmpty()&&peek()=='('){
                pop();
            }
             else{
                printf("Invalid expression: Unmatched parenthesis.\n");
            }
        }
        else if(s=='+'||s=='-'||s=='*'||s=='/'||s== '^'){
            while (!isEmpty()&&precedence(s)<=precedence(peek())&& peek()!='('){
                postfix[j++]=pop();
            }
            push(s);
        }
        else if (isspace(s)){
        }
        else {
            printf("Invalid character in expression: %c\n",s);
        }
        i++;
    }
    while(!isEmpty()){
        if (peek()=='('){
            printf("Invalid expression: Unmatched parenthesis.\n");
        }
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void infixToPrefix(char infix[],char prefix[]) {
    char reversed[n],postfix[n];
    strcpy(reversed,infix);
    reverse(reversed);
    for(int i=0;reversed[i];i++){
        if(reversed[i]=='(')
            reversed[i]=')';
        else if(reversed[i]==')')
            reversed[i]='(';
    }
    infixToPostfix(reversed,postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}
int main() {
    char infix[n],prefix[n];
    printf("Enter an infix expression: ");
   gets(infix);
   infixToPrefix(infix,prefix);
   printf("Prefix expression: %s\n",prefix);
    return 0;
}