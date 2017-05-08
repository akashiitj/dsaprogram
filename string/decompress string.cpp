#include<bits/stdc++.h>
using namespace std;
string f(string &s,int &i,int &sum)
{
    string rs=s.substr(i,1),is="";

    int j=i+1,flag=0,a=0,c=0;
    while(s[j]!=NULL&&(int)s[j]-48>=0&&(int)s[j]-48<=9)
    {
        stringstream ss;
        ss<<((int)s[j]-48);
        is=is+ss.str();

        j++;
        flag=1;
        c++;


    }
    if(flag==1)
    {
        a=atoi(is.c_str());
        sum=sum+a-1;
    }
    if(flag==0)sum++;
    for(int q=1; q<a; q++)
        rs=rs+s.substr(i,1);
    i=j;

    return rs;
}
main()
{
    string s="c4b3a";
    int i=0;
   int sum=1;

    while(s[i]!=NULL)
    {
        string s1=s.substr(0,i);
        string s2=f(s,i,sum);
        cout<<i<<" i"<<endl;
        string s3=s.substr(i);
        s=s1+s2+s3;
        i=sum;
         cout<<i<<" i sum"<<endl;
        cout<<s<<endl;
    }
    cout<<s<<endl;
}
