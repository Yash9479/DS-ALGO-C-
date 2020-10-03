#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

void display()
{
    if(top==NULL)
    {
        cout<<"\n List is empty";
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n Top element is "<<top->data;
}

void push()
{
    int num;
    cout<<"\n Enter the element to be inserted :";
    cin>>num;
    struct Node *ptr=new Node();
    ptr->data=num;
    ptr->next=top;
    top=ptr;
    cout<<"\n List after insertion:";
    display();
}
void pop()
{
    if(top==NULL)
    {
        cout<<"\n List is empty";
        return;
    }
    struct Node *temp=top;
    top=top->next;
    cout<<"\n Element Deleted :"<<temp->data;
    delete temp;
    cout<<"\n List after deletion :";
    display();
}

int main()
{
    int ch;
    do
    {
        cout<<"\n*********************************************************";
        cout<<"\n Enter your choice ";
        cout<<"\n 1.Push";
        cout<<"\n 2.Pop";
        cout<<"\n 3.Display";
        cout<<"\n 4.Exit";
        cout<<"\n Ans: ";
        cin>>ch;
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:cout<<"\n Elements :";
                   display();
                   break;
            case 4:cout<<"\n Good bye";
        }
    }while(ch!=4);
    return 0;
}
