#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

int a[26];
int b[26][26];
int c1[26][26][26];
int d[26][26][26][26];


main()
{
    int t;
    cin>>t;
    while(t--)
    {

        loop(i,0,26)
        {
            a[i]=0;
            loop(j,0,26)
            {
                b[i][j]=0;
                loop(k,0,26)
                {
                    c1[i][j][k]=0;
                    loop(l,0,26)
                    {
                        d[i][j][k][l]=0;

                    }
                }

            }
        }

        string s;
        cin>>s;

        loop(i,0,s.length())
        {
           a[s[i]-97]=1;
           if(i+1<s.length())
           b[s[i]-97][s[i+1]-97]=1;

           if(i+2<s.length())
           c1[s[i]-97][s[i+1]-97][s[i+2]-97]=1;

           if(i+3<s.length())
           d[s[i]-97][s[i+1]-97][s[i+2]-97][s[i+3]-97]=1;
        }
        char c;
        loop(i,0,26)
        {
           if(a[i]==0){
                c='a'+i;
                cout<<c;
                cout<<endl;
                goto qw;
                }
        }
        loop(i,0,26)
        loop(j,0,26)
        {
           if(b[i][j]==0){
                c='a'+i;
                cout<<c;
                c='a'+j;
                cout<<c;
                cout<<endl;
                goto qw;
                }
        }
        loop(i,0,26)
        loop(j,0,26)
        loop(k,0,26)
        {
           if(c1[i][j][k]==0){
                c='a'+i;
                cout<<c;
                c='a'+j;
                cout<<c;
                c='a'+k;
                cout<<c;

                cout<<endl;
                goto qw;
                }
        }

        loop(i,0,26)
        loop(j,0,26)
        loop(k,0,26)
        loop(l,0,26)
        {
           if(d[i][j][k][l]==0){
                c='a'+i;
                cout<<c;
                c='a'+j;
                cout<<c;
                c='a'+k;
                cout<<c;
                c='a'+l;
                cout<<c;
                cout<<endl;
                goto qw;
                }
        }
        qw:;
    }
}
