#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int A[5];
int front = -1;
int rear = -1;

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
	
    
     

	return 0;
}
