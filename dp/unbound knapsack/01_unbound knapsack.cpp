#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    int val[]={10, 40, 50, 70};
    int wt[]={1, 3, 4, 5};
    int W=8;
    n=sizeof(val)/sizeof(int);
    int dp[n+1][W+1];
    memset(dp,-1,((n+1)*(W+1))*(sizeof(int)));
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(j>=wt[i-1])
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
   /* for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    cout<<dp[n][W]<<endl;
    return 0;
}