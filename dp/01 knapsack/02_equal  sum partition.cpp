#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int n,sum=0;
    int ar[]={1,5,5,11};
    n=sizeof(ar)/sizeof(ar[0]);
    for(i=0;i<n;i++)
    {
        sum=sum+ar[i];
    }
    sum=sum/2;
    int dp[n+1][sum+1];
    memset(dp,-1,((n+1)*(sum+1)*sizeof(int)));
    for(j=0;j<=sum;j++)
    {
        dp[0][j]=0;
    }
    for(i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j>=ar[i-1])
            {
                dp[i][j]=dp[i-1][j-ar[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]==1)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}