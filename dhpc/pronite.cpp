#include<bits/stdc++.h>
using namespace std;
struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;
main()
{  ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int sum=0;
    string s1,s2;
    cin.get();
    while(n--)
    {   cin>>s1;
        sum=0;

        while(cin.get()!='\n')
        {
            cin>>s2;

            if(s1==s2)sum=sum+0;
            if((s1=="omega"&&s2=="beta")||(s1=="beta"&&s2=="omega"))
                sum=sum+6;
            else if((s1=="omega"&&s2=="theta")||(s1=="theta"&&s2=="omega"))
                sum=sum+8;
           else  if((s1=="theta"&&s2=="beta")||(s1=="theta"&&s2=="beta"))
                sum=sum+2;
            s1=s2;
         }

         cout<<sum<<endl;
        }

    }

