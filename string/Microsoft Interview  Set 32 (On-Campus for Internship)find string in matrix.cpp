#include<iostream>
using namespace std;
bool f(char **a,string s,int si,int i,int j,int m,int n)//string index
{  cout<<"d"<<endl;
    if(si==s.length()-1)
        return true;
   else if((i+1)>=0 && i+1<m &&j>=0 &&j<n&&a[i+1][j]==s[si+1])
    {
       return f(a,s,si+1,i+1,j,m,n);
    }



   else if((i)>=0 && i<m &&j+1>=0 &&j+1<n &&a[i][j+1]==s[si+1])
    {
       return f(a,s,si+1,i,j+1,m,n);
    }

    else if((i-1)>=0 && i-1<m &&j>=0 &&j<n &&a[i-1][j]==s[si+1])
    {
       return f(a,s,si+1,i-1,j,m,n);

    }

    else if((i)>=0 && i<m &&j-1>=0 &&j-1<n &&a[i][j-1]==s[si+1])
    {
     return f(a,s,si+1,i,j-1,m,n);

    }
    else return false;

}
main()
{   int pix,piy;//passing index to function starting
    char **a;
    int m,n;
    cin>>m;
    cin>>n;
    string s;
    cin>>s;
     //cout<<"d";
    a=new char *[m];
    for(int i=0;i<m;i++)
    {
      a[i]=new char[n];
        for(int j=0;j<n;j++)
            {cin>>a[i][j];
            if(s[0]==a[i][j])
            {
                pix=i;
                piy=j;
            }
            }
    }
    //cout<<"d";
   cout<< f(a,s,0,pix,piy,m,n);

}
