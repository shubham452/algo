#include<bits/stdc++.h>
using namespace std;
int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int n=strlen(x);
    int m=strlen(y);
    int i,j;
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(x[i-1] == y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    int index=dp[n][m];
    char ch[index];
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            ch[index-1]=x[i-1];
            //cout<<index<<"  "<<ch[index-1]<<endl;
            index--;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(i=0;i<dp[n][m];i++)
    {
        cout<<ch[i];
    }
    return 0;
}