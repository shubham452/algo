#include<bits/stdc++.h>
using namespace std;
int main()
{
    int wt[]={10,20,30};
    int val[]={60,100,120};
    int W=50;
    int i,j,n;
    n=sizeof(val)/sizeof(val[0]);
    
    int dp[n+1][W+1];
    memset(dp,0,((n+1)*(W+1))*(sizeof(int)));
    cout<<dp[0][1]<<endl;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
  /*  for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    } */
    cout<<dp[n][W];
    return 0;
}