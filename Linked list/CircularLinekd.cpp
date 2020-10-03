using namespace std;
#include<iostream>

struct Node{
    int data;
    struct Node *next;
};

struct Node *last=NULL;

void display()
{
    if(last==NULL)
    {
        cout<<" List is empty";
    }
    else
    {
        struct Node *temp=last->next;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=last->next);
    }
}

void insertion(int num,int pos)
{
    struct Node *ptr=new Node();
    ptr->data=num;
    if(last==NULL)
    {
        last=ptr;
        ptr->next=last;
    }
    else
    {
       ptr->next=last->next;
       last->next=ptr;
       if(pos==2)
        last=ptr;
    }
    cout<<" \nList after insertion :";
    display();
}

void deletion(int pos)
{
    if(last==NULL)
    {
        cout<<"\n List is Empty ";
        return;
    }
    struct Node *prev,*temp=last->next;
    if(last==last->next)
    {
        delete temp;
        last=NULL;
    }
    else if(pos==1)
    {
        last->next=temp->next;
        delete temp;
    }
    else if(pos==2)
    {
        do
        {
            prev=temp;
            temp=temp->next;
        }while(temp!=last);
        prev->next=last->next;
        last=prev;
        delete temp;
    }
    cout<<"\n List after deletion ";
    display();

}

int main()
{
    int ch,num,pos;
    cout<<"--------------------------------------CIRCULAR LINKED LIST-----------------------------";
    do
    {
        cout<<"\n ************************************************************";
         cout<<"\n Enter your choice";
         cout<<"\n 1.Insertion";
         cout<<"\n 2.Deletion";
         cout<<"\n 3.Display";
         cout<<"\n 4.Exit";
         cout<<"\n Ans:";
         cin>>ch;
         if(ch==1)
         {
             cout<<"\n Enter the element you want to insert:";
             cin>>num;
             cout<<"\n Enter the position of element you want to add \n 1.Begining 2.End";
             cout<<"\n Choose from the given option :";
             cin>>pos;
             insertion(num,pos);
         }
         else if(ch==2)
         {
             cout<<"\n Enter the position of element you want to delete \n 1.Begining 2.End";
             cout<<"\n Choose from the given option :";
             cin>>pos;
             deletion(pos);
         }
         else if(ch==3)
         {
             cout<<"\n Elements :";
             display();
         }
         else if(ch==4)
            cout<<"\nGood Bye";
         else
         {
             cout<<"\n Wrong Input choose wisely";
         }

    }while(ch!=4);

return 0;
}
