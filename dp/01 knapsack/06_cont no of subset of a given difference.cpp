#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int diff=1;
    int ar[]={0,0,1};
    int n=sizeof(ar)/sizeof(int);
    int sum=accumulate(ar,ar+n,0);
    int dp[n+1][sum+1];
    memset(dp,-1,((n+1)*(sum+1)*(sizeof(int))));
    int val=(sum-diff)/2;
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
            if(j>=ar[i-1])
            {
                dp[i][j]=dp[i-1][j] + dp[i-1][j-ar[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }   
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    } 
    /*int d,x,count=0;
    for(j=0;j<=sum/2;j++)
    {
        if(dp[n][j]==1)
        {
            x=sum-j;
            cout<<"x and j are: "<<x<<"  "<<j<<endl;
            cout<<abs(x-j)<<endl;
           // if(abs(x-j)==diff)
           if(sum-(2*j)==1)
            {
                count++;
            }
        }
    }
    cout<<"count is "<<count<<endl;*/
    cout<<"count is "<<dp[n][val];
    return 0;
}