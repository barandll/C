#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node* link;
	
};

struct node *head;	
struct node *rear;	

struct node *allocate()
{
	struct node *tmp = malloc(sizeof(struct node));

	return tmp;
}

int print()
{
   int counter =0;
   struct node *n = head;
   printf("the list: \n");
   while(n)
   {
       printf("-> %d \n",n->data);
       n=n->link;
       counter++;

   }

   printf("you have %d items\n",counter );
 
 return 0; 
}

int insert_front(int data)
{
	struct node *n = allocate();
	n->data = data;
	n->link = head;
   
   if(rear == NULL)
   {
   	rear = n;
   }
    
    head=n;
}

int insert_rear(int data)
{
	struct node *n = allocate();
	n->data = data;
	n->link = NULL;
   
    if(rear != NULL)
    {
    	rear->link = n;
    	rear =n;
    }
    else
    {
    	head = n;
    	rear = n;
    }
}
  
// int find(int what)
// {    

// 	struct node *n = head;
// 	while(n)
// 	{
//       if(n->data == what)
      
//       n = n->link;
      
//       return 1;
// 	}
// 	return 0;
// }

// int delete(int what)
// { 
// 	struct node *n = head;
// 	struct node *prev = NULL;
// 	struct node *tmp = NULL;
// 	while(n)
// 	{
//       if(n->data == what)
//       {
//         tmp = n;
//         if(prev)
//               prev->link = n->link;
//          else
//       	      head = n->link;

//         if(tmp->link == NULL)
//       	     rear=prev;
      
//       free(tmp);
//       return 1;
//       }
     
//      prev = n;
//      n= n->link;

//     }
//     return 0;
 
// } 

int main(int argc, char const *argv[])
{
	insert_front(3);
	insert_front(4);
	insert_rear(3);
		insert_rear(7);
			insert_rear(5);
				insert_rear(6);
					insert_rear(8);
    
    print();

    delete(3);

    print();

	
	return 0;
}