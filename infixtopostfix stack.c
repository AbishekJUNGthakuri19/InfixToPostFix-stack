#include<stdio.h>
#define STACK_SIZE 30
int top=-1;
char stack[STACK_SIZE];
void push(char x){
	if(top<STACK_SIZE-1){
		stack[++top]=x;
	}
	else 
	printf("\nStack is full");	
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    } 
	else {
        printf("Stack is Empty\n");
        return '\0'; 
    }
}

int isoperator(char ch){
	return ch=='+' || ch=='-'||ch=='/'||ch=='*'||ch=='^';
}
int priority(char x){
  if(x=='(')
  return 0;
  if(x=='+'||x=='-')
  return 1;
  if(x=='*'||x=='/')
  return 2;
  if(x=='^')
  return 4;  
  return -1;
}

void InfixToPostfix(char infix[30],char postfix[30]){
	int i=0,j=0;
	char x;
	while(infix[i]!='\0'){
		if(!isoperator(infix[i]) && infix[i]!='(' && infix[i]!=')'){
			postfix[j]=infix[i];
			i++;
			j++;
		}
		else if(infix[i]=='('){
			push(infix[i]);
			i++;
		}
		else if(infix[i]==')'){
			while((x=pop())!='('){
				postfix[j]=x;
				j++;
			}
			i++;
		}
		else if(priority(infix[i])<=priority(stack[top])){
			while(top!=-1 && priority(infix[i])<=priority(stack[top])){
				x=pop();
				postfix[j]=x;
				j++;
			}
		}
		else{
			push(infix[i]);
			i++;
		}	
	}
	while(top!=-1){
		x=pop();
		postfix[j]=x;
		j++;
	}
	postfix[j]='\0';
}

int main(){
	char infix[30],postfix[30];
	printf("Enter the infix expression:");
	scanf("%s",&infix);
	InfixToPostfix(infix,postfix);
	printf("\nThe postfix experssion is: %s",postfix);
}


