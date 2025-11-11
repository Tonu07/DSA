#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define m 100
#define n 50
char stack[n];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==n-1;
}
void push(char item){
    if (isFull()){
        printf("Stack Overflow!\n");
    }
    stack[++top]=item;
}
char pop(){
    if(isEmpty()){
        return '\0';
    }
    return stack[top--];
}
char peek(){
    if (isEmpty()){
        return '\0';
    }
    return stack[top];
}
int precedence(char op){
    if (op=='^')
        return 3;
    else if (op =='*'||op =='/')
        return 2;
    else if (op =='+'||op =='-')
        return 1;
    else
        return 0;
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
    while (!isEmpty()){
        if (peek() == '('){
            printf("Invalid expression: Unmatched parenthesis.\n");
        }
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main() {
    char infix[m];
    char postfix[m];
    printf("Enter an infix expression: ");
    fgets(infix,m,stdin);
    infix[strcspn(infix,"\n")]=0;
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}