#include<bits/stdc++.h>
using namespace std;
int main()
{
    int val[]={2,3,7,8,10};
    int sum=11;
    int i,j,n;
    n=sizeof(val)/sizeof(val[0]);
    int dp[n+1][sum+1];
    memset(dp,0,((n+1)*(sum+1)*sizeof(int)));

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(val[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-sum[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    } 
    cout<<dp[n][W];
    return 0;
}