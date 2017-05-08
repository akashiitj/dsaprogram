#include<bits/stdc++.h>
using namespace std;
unsigned long long count(string s,char c)
{  unsigned long long c1=0;
    for(unsigned long long i=0;i<s.length();i++)
        if(s[i]==c)c1++;
    return c1;
}
main()
{
    unsigned long long n,k,sum=0;
    cin>>n>>k;
    string s;
    cin>>s;
   unsigned long long a[256]={0};
   for(unsigned long long i=0;i<s.length();i++)
   {
       a[s[i]]++;
   }
   sort(a,a+256);

   unsigned long long i=255,as=0;
   while(a[i]<=k)
   {
       as=as+a[i]*a[i];
       k=k-a[i];
       i--;
   }
   as=as+k*k;
    cout<<as<<endl;
}
