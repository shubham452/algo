#include<bits/stdc++.h>
using namespace std;
int lcs(char *x, char *y, int n, int m)
{
    int dp[n+1][m+1];
    if(n==0 || m==0)
    {
        return 0;
    }
    else if(x[n-1]==y[m-1])
    {
        return dp[n][m]= 1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return dp[n][m]= max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int n = strlen(X);
    int m = strlen(Y);
    cout<<"Length of LCS is "<< lcs( X, Y, n, m ) ;
    return 0;
}