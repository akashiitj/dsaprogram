#include<bits/stdc++.h>
using namespace std;

void f(int i,int flag,vector<int> v,int A,vector<int> &fa)
{
    if(i==A)
    {
        int ans=0;
        reverse(v.begin(),v.end());
        for(int i1=0;i1<i;i1++)
        {
            ans=ans+v[i1]*(1<<i1);
        }
        fa.push_back(ans);

        return;

    }
    if(flag==0)
    {
        v.push_back(0);
        f(i+1,flag,v,A,fa);
        v.pop_back();

        v.push_back(1);
        f(i+1,1-flag,v,A,fa);
        v.pop_back();
    }

   else if(flag==1)
    {
        v.push_back(1);
        f(i+1,1-flag,v,A,fa);
        v.pop_back();

        v.push_back(0);
        f(i+1,flag,v,A,fa);
        v.pop_back();
    }
}

vector<int> gc(int A) {
    vector<int> v;
    vector<int> fa;
    f(0,0,v,A,fa);
    return fa;
}

main()
{
   vector<int> v;
   v=gc(2);

   for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}
