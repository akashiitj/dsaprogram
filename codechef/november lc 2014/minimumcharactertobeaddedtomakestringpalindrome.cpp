#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,i,j;
    cin>>t;string s;
    while(t--)
    {
        cin>>s;
        i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {
                s.insert(j+1,s.substr(i,1));
                i++;
            }
        }
        cout<<s<<endl;
    }
}
