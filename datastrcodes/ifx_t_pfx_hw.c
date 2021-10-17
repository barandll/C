#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50    
     
char stack[SIZE];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == SIZE)
      return 1;
   else
      return 0;
}

char peek() {
   return stack[top];
}

char pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(char data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int prd(char symbol)
{                 /* Function for precedence */
    
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')         
	{
		return(1);
	}
	else
	{
		return(0);
	}
}



int main()

{                        
    char infix[50],postfix[50],chrc,elem;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    while( (chrc=infix[i++]) != '\0')
    {
        if( chrc == '(') push(chrc);
        else
            if(isalnum(chrc)) postfix[k++]=chrc;
            else
                if( chrc == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop(); 
                }
                else
                {      
                    while( prd(stack[top]) >= prd(chrc) )
                        postfix[k++]=pop();
                    push(chrc);
                }
    }
    while( stack[top] != '#')     
        postfix[k++]=pop();
    postfix[k]='\0';         
    printf("\nPostfix Expression =  %s\n",postfix);
return 0;
}
