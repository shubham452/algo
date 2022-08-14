#include<bits/stdc++.h>
using namespace std;
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
    int k,count;
    int ans=INT_MAX;
    if(i>=j || ispalindrome(str,i,j))
    {
        return 0;
    }
    for(k=i;k<j;k++)
    {
        count=mcm(str,i,k)+mcm(str,k+1,j)+1;
        ans=min(count,ans);
    }
    return ans;
}
int main()
{
    string str="ababbbabbababa";
    int n=str.length();
    cout<<mcm(str,0,n-1);
}