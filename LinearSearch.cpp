#include <iostream>

using namespace std;

int main()
{
    int arr[6]={10,25,9,56,15,59};
    int count=0;
    int search;
    cout<<"Enter a number to search in array:- ";
    cin>>search;
    for(int i=0;i<6;i++)
    {
        if(search==arr[i])
        {
            cout<<search<<" is found in the array.";
            count++;
            break;
        }

    }
    if(count==0)
    {
        cout<<search<<" is not found in the array.";
    }

    return 0;
}