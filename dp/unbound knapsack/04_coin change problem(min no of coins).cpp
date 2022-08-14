#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    int ar[]={9,6,5,1};
    int sum=11;
    n=sizeof(ar)/sizeof(int);
    int dp[n+1][sum+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
            }
            else if(i==0)
            {
                dp[i][j]=1e5;
            }
            else if(ar[i-1]<=j)
            {
                dp[i][j]=min(1+dp[i][j-ar[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    if(dp[n][sum]>1e4)
    cout<<-1;
    else
    cout<<dp[n][sum];
    return 0;
}