#include<bits/stdc++.h>
using namespace std;
int mcm(int ar[],int i, int j)
{
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int min=INT_MAX;
    int count;
    for(int k=i;k<j;k++)
    {
        count=mcm(ar,i,k)+mcm(ar,k+1,j)+ar[i-1]*ar[k]*ar[j];
        if(count<min)
        {
            min=count;
            dp[i][j]=min;
        }
    }
    return min;
}
int main()
{
    int ar[]={1, 2, 3, 4, 3};
    int n=sizeof(ar)/sizeof(ar[0]);
    cout<<mcm(ar,1,n-1);
    return 0;
}