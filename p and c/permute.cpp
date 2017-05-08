#include<bits/stdc++.h>
using namespace std;
#define n 4
string str[n]={"a","b","c","d"};
//string s;
int mark[n];


void perm(string s,int k)
{
    if(k==n)
    {
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(mark[i]==0)
        {
        mark[i]=1;
        perm(s+str[i]+" ",k+1);
        mark[i]=0;

        }


    }
}
int main()
{
    for(int i=0;i<n;i++)
    {
    mark[i]=0;//keep record of which string is already filled
    }
    string s;
    perm(s,0);
}
