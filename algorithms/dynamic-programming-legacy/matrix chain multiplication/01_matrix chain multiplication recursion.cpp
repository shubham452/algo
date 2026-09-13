#include<bits/stdc++.h>
using namespace std;
int mcm(int ar[], int i, int j)
{
    if(i==j)
    {
        return 0;
    }
    int k;
    int count;
    int min=INT_MAX;
    for(k=i;k<j;k++)
    {
        count=mcm(ar,i,k)+mcm(ar,k+1,j)+ar[i-1]*ar[k]*ar[j];
        if(min>count)
        {
            min=count;
        }
    }
    return min;
}
int main()
{
    int ar[]={1, 2, 3, 4, 3};
    int n=sizeof(ar)/sizeof(ar[0]);
    cout<<mcm(ar,1,n-1);
    return 0;
}