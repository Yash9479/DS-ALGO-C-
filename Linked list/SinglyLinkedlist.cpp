#include<iostream>
using namespace std;

int que[20],front_=-1,rear=-1,siz;

void Enqueue(int val)
{
    if((front_==0 && rear==siz-1) || (front_== rear+1))
    {
        cout<<"\n Queue Overflow ";
        return ;
    }
    else if(front_==-1)
    {
        front_ =0;
        rear=0;
    }
    else if(rear==siz-1)
        rear=0;

    else
        rear= rear+1;

    que[rear]=val;
}

void dequeue()
{
    if(front_== -1 )
    {
        cout<<"\n Queue Underflow";
        return ;
    }
    cout<<"\n Deleted Element from queue is :"<<que[front_];
    if(front_==rear)
    {
        front_=-1;
        rear=-1;
    }
    else if(front_== siz-1)
    {
        front_=0;
    }
    else
        front_+=1;

}
void display()
{
    int f= front_,r=rear;
    if(front_==-1)
    {
        cout<<"\n Queue is empty ";
        return ;
    }
    cout<<"\n Queue elements are :";
    if(f<=r)
    {
        while(f<=r)
        {
            cout<<que[f]<<" ";
            f++;
        }
    }
    else
    {
        while(f <= siz-1)
        {
            cout<<que[f]<<" ";
            f++;
        }
        f=0;
        while(f<=r)
        {
            cout<<que[f]<<" ";
            f++;
        }
    }
}
int main()
{
    int ch,val;

    cout<<"\n Enter the size of list :";
    cin>>siz;

    do
    {
        cout<<"\n Enter your choice";
        cout<<"\n 1.Enqueue";
        cout<<"\n 2.Dequeue";
        cout<<"\n 3.Display";
        cout<<"\n 4.Exit";
        cout<<"\n Ans:";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n Enter the element to be inserted :";
                   cin>>val;
                   Enqueue(val);
                   break;

            case 2:dequeue();
                   break;

            case 3:display();
                   break;

            case 4:cout<<" Goodbye";
                   break;

        }

    }while(ch!=4);

    return 0;
}
