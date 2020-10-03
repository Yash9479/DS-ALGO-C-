#include <stdio.h>
#include <stdlib.h>

/* Structure for queue with array size and pointers */
struct queue
{
 int s[3];
 int front,rear;
}st;

/* Function to check if the queue is full */
int full()
{
 if(st.rear >= 2)
 return 1;
 else
    return 0;
}

/* Function to check if the queue is empty */
int empty()
{
 if(st.front == -1)
 return 1;
 else

    return 0;
}

/* Function to insert elements in a queue */
void enqueue(int num)
{
 if(st.front == -1)    // The queue is initially empty
 st.front++;
 st.rear++;
 st.s[st.rear]=num;
}

/* Function to delete elements in a queue */
int dequeue()
{
 int x;
 x = st.s[st.front];
 if(st.front==st.rear)    // The queue contains only one element
 st.front=st.rear=-1;
 else
 st.front++;   // Increment front

printf("\nDequeued Element : %d",x);
}

/* Function to display the elements in the queue */
void display()
{
 int i;
 if(empty())
 printf("\nEMPTY QUEUE\n");
 else
 {
 printf("\nQUEUE ELEMENTS : ");
 for(i=st.front;i<=st.rear;i++)
 printf("%d ",st.s[i]);

}}

/* Main function */
int main()
{
 int num,choice;
 st.front = st.rear = -1;
 while(1)
 {
 printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\n");
 scanf("%d",&choice);
 switch (choice)
 {
 case 1:
 if(full())
 {
 printf("\nQUEUE IS FULL\n");
 }
 else
 {
 printf("\nEnter item : ");
 scanf("%d",&num);
 enqueue(num);
 }
 break;
 case 2:
 if (empty())
 {
 printf("\nEMPTY QUEUE\n");
 }
 else
 {
 dequeue();
 }
break;
 case 3:
 display();
 break;
 default: exit(0);
 }}
 return 0;
}
