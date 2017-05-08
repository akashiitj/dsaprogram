#include<bits/stdc++.h>
using namespace std;

string its(int n)
{
    string s;
    {
        stringstream ss;
        ss<<n;
        s=ss.str();
    }
    return s;
}

void com(string &s)
{
    int i=0;
    int l=s.length();
    int p=0;
    while(i<l)
    {
        s[p]=s[i];
        char c=s[i];
        int count=0;
        while(i<l&&s[i]==c)
         {
             count++;
             i++;
         }
        if(count>1)
        {
            p++;
            int j=0;
            string s2=its(count);
            while(j<s2.length())
            {
                s[p]=s2[j];
                p++;
                j++;
            }
        }
        else p++;

    }
s.resize(p);
}

main()
{
    string s;
    cin>>s;
    com(s);
    cout<<s;
}
