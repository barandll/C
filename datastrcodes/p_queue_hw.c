#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int A[5];
int front = -1;
int rear = -1;
int P_front = -1;
int P_rear = -1;
int P_A[5];
// int F_A[5];

int IsEmpty()
{

 if(front == -1 && rear == -1)
    return 1;
 else
   return 0;

}

int IsFull()
{

 if(rear-front == -1 || rear-front == N-1)
	return 1;
 else 
	return 0;

}

void P_Enque(int priority)
{
 if (((P_rear+1)% N == P_front))
	return;
 else if (IsEmpty())
 {
 front = 0;
 rear = 0;
 P_A[rear] = priority;
 }
 else
 {
	P_rear = (P_rear+1)%N;
 }
 P_A[P_rear] = priority;

}

void P_Dequeue()
{
	if (IsEmpty())
		return;
	else if (P_front == P_rear)
	{	
         P_front = -1;
         P_rear = -1;
    }     
    else
    P_front = (P_front +1)%N;
}

void display_queue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", A[front]);
    }
 
    front = 0;
}

void display_P_queue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", P_A[front]);
    }
 
    front = 0;
}

void Enqueue(int x)
{

 if (((rear+1)% N == front))
	return;
 else if (IsEmpty())
 {
 front = 0;
 rear = 0;
 A[rear] = x;
 }
 else
 {
	rear = (rear+1)%N;
 }
 A[rear] = x;
}

void Dequeue()
{
	if (IsEmpty())
		return;
	else if (front == rear)
	{	
         front = -1;
         rear = -1;
    }     
    else
    front = (front +1)%N;
}

int peek(){

	return A[front];
}



int main(int argc, char const *argv[])
{
   int i=0;
   int j=0;

	Enqueue(5); 
	P_Enque(4);

	Enqueue(8); 
	P_Enque(3);
	
	Enqueue(9); 
	P_Enque(5);
	
	Enqueue(10); 
	P_Enque(2);
	
	Enqueue(4); 
	P_Enque(1);

 display_queue();
 printf("\n");
 display_P_queue();
 printf("\n");
 
 //teacher ı tried to do it with the arrays but ı failed, 
 //ı looked at the ınternet for solutions but there was nothing about a priority queue



	return 0;
}
