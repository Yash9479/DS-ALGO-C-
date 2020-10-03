#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;
int count1=1;

void display()
{
    struct Node *temp=head;
    if(temp==NULL)
    {
        cout<<"List Empty";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
void insertAtBegin(int num)
{
    Node *ptr=new Node();
    ptr->data=num;
    ptr->prev=NULL;
    ptr->next=head;
    head=ptr;
    count1++;
    cout<<"\n List after insertion :";
    display();
}

void insertAtEnd(int num)
{
    Node *ptr=new Node();
    ptr->data=num;
    ptr->next=NULL;
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    count1++;
    cout<<"\n List after insertion :";
    display();
}
 void insertAtMid(int num,int pos)
 {
     Node *ptr=new Node();
     ptr->data=num;
     struct Node *temp=head;
     for(int i=1;i<pos-1;i++)
     {
         temp=temp->next;
     }
     ptr->next=temp->next;
     ptr->prev=temp;
     temp->next->prev=ptr;
     temp->next=ptr;
     count1++;
     cout<<"\n List after insertion :";
     display();
 }

 void delFromBegin()
 {
     if(head==NULL)
     {
         cout<<"List is empty";
         return;
     }
     struct Node *ptr=head;
     head=ptr->next;
     delete ptr;
     count1--;
     cout<<"\n List after deletion :";
     display();
 }

 void delFromEnd()
 {
     if(count1-1==1)
     {
         delFromBegin();
         return;
     }
     struct Node *before,*temp=head;
     while(temp->next!=NULL)
     {
         before=temp;
         temp=temp->next;
     }
     before->next=NULL;
     delete temp;
     count1--;
     cout<<"\n list after deletion :";
     display();

 }
 void delFromMid(int pos)
 {
     struct Node *ptr;
     ptr=head;

     for(int i=1;i<pos;i++)
     {
         ptr=ptr->next;
     }
     cout<<(ptr->next)->data;
     cout<<(ptr->prev)->data;
     cout<<(ptr->prev)->data;
     (ptr->prev)->next = ptr->next;
     (ptr->next)->prev = ptr->prev;
     free(ptr);
     count1--;
     cout<<"\n list after deletion :";
     display();
 }

int main()
{
   int ch,pos,num;
   cout<<"--------------------------------------------Doubly Linked List----------------------------------------------------";
   do
   {
       cout<<"\n***********************************************";
       cout<<"\n Enter your choice :";
       cout<<"\n 1.Insert an element in a list";
       cout<<"\n 2.Delete an element in a list";
       cout<<"\n 3.Display elements of the list";
       cout<<"\n 4.Exit";
       cout<<"\n Ans:";
       cin>>ch;
       if(ch==1)
       {
           cout<<"\n Enter the position of element:";
           cin>>pos;
           cout<<"\n Enter the element to be inserted :";
           cin>>num;
           if(pos>count1)
           {
               cout<<" Invalid input \n Total elements are :"<<count1-1;
           }

           else if(pos==1)
           {
               insertAtBegin(num);
           }
           else if (pos==count1)
           {
               insertAtEnd(num);
           }
          else
           {
               insertAtMid(num,pos);
           }
       }

       else if(ch==2)
       {
           cout<<"\n Enter the position of element you want to delete:";
           cin>>pos;
           if(pos>count1-1)
           {
               cout<<"\n Invalid Input \n Total elements are :"<<count1-1;
           }
           else if(pos==1)
           {
               delFromBegin();
           }

           else if(pos==count1-1)
           {
               delFromEnd();
           }
           else
           {
               delFromMid(pos);
           }
       }
       else if(ch==3)
       {
           cout<<"\n Elements:";
           display();
       }

   }while (ch!=4);

   return 0;
}




