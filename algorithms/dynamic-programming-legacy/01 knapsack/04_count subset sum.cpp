#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int sum=10;
    int ar[]={2,3,5,6,8,10};
    int n=sizeof(ar)/sizeof(ar[0]);
    int dp[n+1][sum+1];
    memset (dp,-1,((n+1)*(sum+1)*sizeof(int)));
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
            if(ar[i-1]<=j)
            {
                //in this dp[i-1][j] gives us the whether we can get j from using the values from 0 to (i-1) and
                // dp[i-1][j-ar[i-1]] tells us whether we can get j from using the values from 0 to i and therefore we add 
                //both to get total count 
                dp[i][j]=dp[i-1][j-ar[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }*/
    cout<<"count is "<<dp[n][sum];
    return 0;
}