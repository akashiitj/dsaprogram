#include<iostream>
#include<string>
using namespace std;
struct strct
{
    int count;
    int at;//arrival time
};
void  f(string s)
 {
    strct a[26];
    int t=1,x=-1,i;
     for( i=0;i<26;i++)
    {
       a[i].count=0;
       a[i].at=0;

    }
//cout<<s.length()<<endl;
    for( i=0;i<s.length();i++)
    {
        a[s[i]-97].count++;
       // cout<<s[i]-97<<a[s[i]-97].count<<endl;
        if(a[s[i]-97].at==0)
            {
        //cout<<t<<endl;
        a[s[i]-97].at=t;
        t++;
            }
    }

    /* for( i=0;i<26;i++)
    {
      cout<< a[i].count<<" ";
      cout<< a[i].at;
      cout<<endl;
    }*/
    for( i=0;i<26;i++)
    {
       if(a[i].count==1)
       {   t=a[i].at;
           x=i;
            break;
       }

    }
    cout<<i<<endl;
    for(int j=i;j<26;j++)
    {
        if(a[i].count==1)
        {
            if(a[i].at<t){
                t=a[i].at;
            x=i;
            }
        }
    }
    char c=97+x;
    cout<<c<<endl;
}
main()
{
   f("abcab");
}
