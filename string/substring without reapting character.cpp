#include<iostream>
#include<string>
using namespace std;
int f(string s)
{   string m;//max string
    int l=s.length();
    int i=0,j=0,ml=0;
    int visit[256]={0};
    while(j<l)
    {
        if(visit[s[j]]==0)
        {
            visit[s[j]]=1;
            j++;
            //cout<<'j'<<j<<endl;
        }
        else
        {   // cout<<'j'<<j<<'i '<<i<<endl;
            if(j-i>ml)
            {   m="";
                for(int q=i;q<j;q++)
                    m=m+s[q];
            }
            ml=max(ml,j-i);

            while(s[j]!=s[i])
            {
                 visit[s[i]]=0;
                i++;
            }
            i++;j++;
        }

    }
    if(j-i>ml)
            {   m="";
                for(int q=i;q<j;q++)
                    m=m+s[q];
            }
    cout<<m<<endl;
    return max(ml,j-i);
}
main()
{   string s;
    cin>>s;
    cout<<f(s)<<endl;
}

