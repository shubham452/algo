#include<bits/stdc++.h>
using namespace std;
int knapsack(int val[], int wt[], int W, int n)
{
    if(n==0||W==0)
    return 0;

    if(wt[n-1]<=W)
    {
        return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
    }
    else
    {
        return knapsack(val,wt,W,n-1);
    }
}
int main()
{
    int wt[]={10,20,30};
    int val[]={60,100,120};
    int W=50;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val,wt,W,n);
    return 0;
}