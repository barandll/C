#include <stdio.h>
#include <stdlib.h>


#define SIZE 100
#define SENT -1

int stack[SIZE];
int top = -1;

void push(int element)
{
 if(top >= SIZE)
 {
 printf("stack overflow,unable to add more element to the stack\n");
 return;
}

 top++;
 
 stack[top]=element;
 
 printf("data %d is pushed to the stack",element);


}

int pop()
{
 if(top<0)
 {
   printf("stack is empty");
   
   return SENT;
 }
 
 return stack[top--];

}


int main()
{

  int option,data;
  
  while(1)
  {
  printf("press 1 to push data\n");
  printf("press 2 to pop the data\n");
  printf("press 3 to see the size of the stack\n");
  printf("press 4 to exit\n");
  printf("------------------------\n");
  printf("enter your choise\n");
  
  scanf("%d", &option);
  
  
  switch(option)
  {
     case 1:
       printf("enter the data to push into stack\n");
       scanf("%d",&data);
       
       push(data);
       break;
       
    case 2:
      data = pop();
      
      if (data != SENT)
        printf("data ==> %d has been popped out of the stack\n", data);
        break;
        
    case 3:
      printf("stack is currently at %d\n" , top+1);
      
      break;
      
    case 4:
      printf("exiting..\n");
      exit(0);
      break;
      
      
    default:
     printf("invalid choise of option\n");
     
   };
  
  printf("\n\n\n");
  
  
  
  }
  
  


  return 0;
}


