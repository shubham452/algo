#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    string x="agbcba";
    string y=x;
    reverse(y.begin(),y.end());
    int n=x.size();
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
                if(x[i-1] == y[j-1])
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
    cout<<n-dp[n][n];
    return 0;
}