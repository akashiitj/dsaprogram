#include<bits/stdc++.h>
using namespace std;
#define n 4
string str[n]={"this","is","glass","mam"};
//string s;
int mark[n];


void perm(string s,int k)
{
    if(k==n)
    {
        cout<<s<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if(mark[i]==0)
        {
        mark[i]=1;
        perm(s+str[i]+" ",k+1);
        mark[i]=0;
        //s.erase(s.length()-str[i].length()-1,str[i].length()+1);
        }


    }
}
int main()
{
    for(int i=0;i<n;i++)
{
    mark[i]=0;
}
string s;
    perm(s,0);
}
