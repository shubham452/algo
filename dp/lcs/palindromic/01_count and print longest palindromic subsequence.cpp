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
    cout<<dp[n][n]<<endl;
    i=n;
    j=n;
    int index=dp[n][n];
    char ch[index];
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            ch[index-1]=x[i-1];
           // cout<<index<<"  "<<x[i-1]<<endl;
            index--;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                ch[index-1]=x[i-1];
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(i=0;i<dp[n][n];i++)
    {
        cout<<ch[i];
    }
    return 0;
}