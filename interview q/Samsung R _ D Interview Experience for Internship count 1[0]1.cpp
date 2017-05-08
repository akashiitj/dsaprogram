#include<bits/stdc++.h>
using namespace std;
main()
{
    string s;
    cin>>s;
    int i=0;
    int c=0,mc=0,j;
    while(i<s.length())
    {   c=0;
        if(s[i]=='1'&&i<s.length())
        {   cout<<"aa "<<endl;
            j=i+1;
            while(j<s.length()&&s[j]=='0')
              {    cout<<"aab "<<endl;
                   c++;
                   j++;
              }
            if(j<s.length()&&c>0&&s[j]=='1')
                mc++;
         i=j;
        }
        else i++;

    }
    cout<<mc<<endl;
}
