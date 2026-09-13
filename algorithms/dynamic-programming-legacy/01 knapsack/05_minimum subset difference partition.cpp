#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int ar[]={1,5,6,11};
    int n=sizeof(ar)/sizeof(int);
    int  sum;
    sum=accumulate(ar, ar+n, 0);

    int dp[n+1][sum+1];
    memset(dp,-1,((sum+1)*(n+1)*sizeof(int)));
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
                dp[i][j]=dp[i-1][j] || dp[i-1][j-ar[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    //s2-s1 must be minimum and s1 + s2=sum
    //s2=sum-s1, now substitute s2
    //therefore (sum-s1)-s1 must be min
    //therefore sum-2s1 must be minimum 
    int min=sum;
    for(j=0;j<=sum/2;j++)//we have taken sum/2 because 2s1 cannot be greater than sum and here min is s1 and the more nearer is s1 from mid the lesser the difference
    {
        if(dp[n][j]==1)
        {
            min=j;
        }
    }
    //here x and min are s1 and s2
    int x=sum-min;
    cout<<"min is"<<abs(x-min)<<endl;
    return 0;
}