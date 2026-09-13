#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,m;
    string x="adxcpy";
    string y="axy";
    n=x.size();
    m=y.size();
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
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
    if(dp[n][m]==n || dp[n][m]==m)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}