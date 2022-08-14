#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,N;
    int price[]={1, 5, 8, 9, 10, 17, 17, 20};
    n=sizeof(price)/sizeof(price[0]);
    int length[n];
    for(i=0;i<n;i++)
    {
        length[i]=i+1;
    }
    N=sizeof(length)/sizeof(length[0]);
    int dp[n+1][N+1];
    memset(dp,-1,((n+1)*(n+1))*sizeof(int));
    //we have made length in column so that we can store the value like if the length of rod is 2 then what can be maximum profit
    //and we have taken rows as price same as unbounded kanpsack and change the variables like
    //val to price
    //wt to length
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=N;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(j>=length[i-1])
            {
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][N]<<endl;
    return 0;
}