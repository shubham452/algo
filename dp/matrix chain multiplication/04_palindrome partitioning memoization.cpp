#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool ispalindrome(string str, int i, int j)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
int mcm(string str, int i, int j)
{
    memset(dp,-1,sizeof(dp));
    if(i==j || ispalindrome(str,i,j))
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int count,k,ans=INT_MAX;
    
    for(k=i;k<j;k++)
    {
        count=mcm(str,i,k)+mcm(str,k+1,j)+1;
        ans=min(count,ans);
        
    }
    dp[i][j]=ans;
    return ans;

}
int main()
{
    string str = "ababbbabbababa";
    cout<<mcm(str,0, str.length() -1) << endl;
    return 0;
}