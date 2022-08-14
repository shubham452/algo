#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    int coin[]={2,5,3,6};
    int sum=10;
    n=sizeof(coin)/sizeof(int);
    int dp[n+1][sum+1];
    memset(dp,-1,((n+1)*(sum+1))*sizeof(int));
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
            if(j>=coin[i-1])
            {
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
    return 0;
}