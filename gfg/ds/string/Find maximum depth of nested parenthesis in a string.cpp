#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    vector<char> v;

    int ans=0;
    int pa=0;
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(!(s[i]=='('||s[i]==')'))
            continue;
        if(s[i]=='(')
        {
            pa=0;
            c++;
            ans=max(ans,c);
        }
        if(s[i]==')')
        {
            if(c<=0)
            {
                cout<<"no";
                return 0;
            }
            pa++;
            c--;
        }

    }
    cout<<ans;

}
