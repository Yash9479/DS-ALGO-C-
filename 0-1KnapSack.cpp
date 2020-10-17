#include<iostream>
using namespace std;

int KnapSackDP(int tot_wt,int wt[],int val[],int n)
{
    int C[n+1][tot_wt + 1] = {0};
    
    for(int i=0;i<=n; i++)
    {
        for(int w=0;w<=tot_wt; w++)
        {
            if(i==0 || w==0)
            {
                C[i][w] = 0;
            }
            else if(wt[i-1]<=w)
            {
                
                C[i][w] = max(val[i-1] + C[i-1][w - wt[i-1]], C[i-1][w]);
            }
            else
            {
                C[i][w] = C[i-1][w];
            }
        }
    }
    return C[n][tot_wt];
}

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, W;
        cin>>n>>W;
        int wt[n], val[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>wt[i];
        }
        cout << KnapSackDP(W, wt, val, n)<<"\n";
    }
    return 0; 
}