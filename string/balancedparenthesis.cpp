#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    stack<char> st;
    int i=0;
    while(i<s.length())
    {
        if(s[i]=='{')
            st.push('{');
        else if(s[i]=='}')
        {
            if(st.top()=='{')
                st.pop();
            else return false;
        }
        i++;
    }
    if(st.empty()==1)
        return true;
    else return false;
}
main()
{
    string s;
    cin>>s;
    bool b;
    b=check( s);
    cout<<b;
}
