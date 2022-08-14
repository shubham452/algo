#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    string x="aabebcdd";
    string y=x;
    n=x.size();
    int dp[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(x[i-1] == y[j-1] && i!=j)
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}