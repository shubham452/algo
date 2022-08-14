#include<bits/stdc++.h>
using namespace std;
bool isscramble(string s1,string s2)
{
    int n=s1.length();
    if(s1==s2 || n==0)
    {
        return true;
    }
    if(s1.length()!=s2.length())
    {
        return false;
    }
    string copy_s1=s1;
    string copy_s2=s2;
    sort(copy_s1.begin(),copy_s1.end());
    sort(copy_s2.begin(),copy_s2.end());
    if(copy_s1!=copy_s2)
    {
        return false;
    }
    for(int k=1;k<s1.length();k++)
    {
        if(isscramble(s1.substr(0,k),s2.substr(0,k)) && isscramble(s1.substr(k),s2.substr(k)))
        return true;

        if(isscramble(s1.substr(0,k),s2.substr(n-k)) && isscramble(s1.substr(k),s2.substr(0,n-k)))
        return true;
    }
    return false;
}
int main()
{
    string S1 = "coder";
    string S2 = "ocder";
 
    if (isscramble(S1, S2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
 
    return 0;
}