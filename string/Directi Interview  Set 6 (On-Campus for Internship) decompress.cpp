#include<bits/stdc++.h>
using namespace std;
string f(string s,string &rs,int &i ,int &sum)
{
    string is="",rs1="";

    while(s[i]!=NULL&&(int)s[i]-48>9)//rs is string phele se and add character until some interger dosnt comes
    {

        rs=rs+s.substr(i,1);
        i++;
        cout<<i<<endl;

    }

    int j=i,flag=0,a=0,c=0;
    while(s[j]!=NULL&&(int)s[j]-48>=0&&(int)s[j]-48<=9)//next interge
    {
        cout<<j<<" j"<<endl;
        stringstream ss;
        ss<<((int)s[j]-48);
        is=is+ss.str();

        j++;
        flag=1;
        c++;


    }
    if(flag==1)//
    {
        a=atoi(is.c_str());
        sum=sum+a*rs.length()-1;
    }
    if(flag==0)
    {
        sum=sum+rs.length()-1;
    }
    cout<<a<<"a "<<j<<endl;
    for(int q=0; q<a; q++)
        rs1=rs1+rs;
    if(a==0)return rs;
    i=j;

    return rs1;
}
int main()
{
    string s="awwrr2";
    int i=0,sum=1;//sum is used to calculate next i value after one while loop is complete
    int c=0;
    string rs="";
//string s2=f(s,rs,i);/*
    while(s[i]!=NULL)
    {
        //string s1=s.substr(0,i);
        string s2=f(s,rs,i,sum);
        rs=s2;

        string s3=s.substr(i);
        s=s2+s3;
        //i=s2.length();
        cout<<s<<endl;
        i=sum;
        c++;
        if(c==2) return 0;
    }
    cout<<s<<endl;
}
