#include<bits/stdc++.h>
using namespace std;
int solve(string str, int i, int j, bool istrue)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        if(istrue==1)
        {
            return str[i]=='T';
        }
        else
        {
            return str[i]=='F';
        }
    }
    int k,ans=0;
    for(k=i+1;k<=j-1;k=k+2)
    {
        int leftT=solve(str,i,k-1,1);
        int leftF=solve(str,i,k-1,0);
        int rightT=solve(str,k+1,j,1);
        int rightF=solve(str,k+1,j,0);
        if(str[k]=='^')
        {
            if(istrue)
            {
                ans+=(leftT*rightF)+(leftF*rightT);
            }
            else
            {
                ans+=(leftT*rightT)+(leftF*rightF);
            }
        }
        else if(str[k]=='|')
        {
            if(istrue)
            {
                ans+=(leftT*rightF)+(leftF*rightT)+(leftT*rightT);
            }
            else
            {
                ans+=(leftF*rightF);
            }
        }
        else if(str[k]=='&')
        {
            if(istrue)
            {
                ans+=(leftT*rightT);
            }
            else
            {
                ans+=(leftF*rightF)+(leftT*rightF)+(leftF*rightT);
            }
        }
    }
    return ans;
}
int main()
{
    string str = "T|T&F^T";
    
    int n = str.length();
    cout << solve(str,0,n-1,1);
    return 0;
}