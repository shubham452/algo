//https://youtu.be/Lja3xWmDyw4
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";
    int i,j;
    int n=strlen(x);
    int m=strlen(y);
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 ||j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(x[i-1]==y[j-1])
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
    cout<<dp[n][m]<<endl;
    string str;
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            str.push_back(y[j-1]);
            j--;
        }
        else
        {
            str.push_back(x[i-1]);
            i--;
        }
    }
    while(i>0)
    {
        str.push_back(x[i-1]);
        i--;
    }
    
    while(j>0)
    {
        str.push_back(y[j-1]);
        j--;
    }
    reverse(str.begin(),str.end());
    cout<<str;
    return 0;
}