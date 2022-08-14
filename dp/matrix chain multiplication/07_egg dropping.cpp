#include<bits/stdc++.h>
using namespace std;
int eggd(int n, int k)
{
    if(k==0 || k==1)
    {
        return k;
    }
    if(n==1)
    {
        return k;
    }
    int min=INT_MAX;
    int ans=0,x;
    for(x=1;x<=k;x++)
    {
        ans=1+max(eggd(n-1,x-1),eggd(n,k-x));
        if(min>ans)
        {
            min=ans;
        }
    }
    
    return min;
}
int main() {
 
    int n = 2, k = 10;
    cout<<eggd(n, k);
    return 0;
}