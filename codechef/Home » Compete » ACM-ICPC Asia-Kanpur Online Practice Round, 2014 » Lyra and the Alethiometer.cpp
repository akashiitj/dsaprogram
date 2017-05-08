#include<bits/stdc++.h>
using namespace std;

string compare(string x,string y)
{
    int a=0,b=0;
    int i=0;
    while(x[i]==48)
    {
        a++;
        i++;
    }
    i=0;
    while(y[i]==48)
    {
        b++;
        i++;
    }
    int p=x.length()-a;
    int q=y.length()-b;
    string s2=y.substr(b,q);
    string s1=x.substr(a,p);
    if(p!=q)
    {
        if(p>q)
        {
            return(s1);
        }
        else
        {
            return(s2);
        }
    }
    if(s1>=s2)
    {
        if(p==0)
        {
            return("0");
        }
        return(s1);
    }
    else
    {
        return(s2);
    }





}


main()
{


        string s;
        cin>>s;
        int l=s.length();
        //cout<<l<<endl;
        vector<int> v;
        v.push_back(0);
        for(int i=0; i<l; i++)
        {
            if(s[i]>=65&&s[i]<=90)
                v.push_back(i+1);
        }
        v.push_back(l+1);

        string ans="\0";
        if(v.size()==2)
        {
            ans=compare(s,ans);
        }
        if(v.size()>=3)
        {
            for(int i=1; i<v.size()-1; i++)
            {
                string s1=s.substr(v[i-1],v[i+1]-v[i-1]-1);
                s1[v[i]-1-v[i-1]]=57;
                ans=compare(s1,ans);
            }
        }
        cout<<ans<<endl;


}


