
#include<bits/stdc++.h>
using namespace std;

#define vi        vector<int>

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define pb        push_back
#define mp        make_pair

int main()
{
     string a;
     cin>>a;
     vi v1,v2;
     loop(i,0,a.length()-1)
     {
         if(a[i]=='A'&&a[i+1]=='B')
            v1.pb(i);
         if(a[i]=='B'&&a[i+1]=='A')
            v2.pb(i);
     }
     int flag=0;
     loop(i,0,v1.size())
     {
         loop(j,0,v2.size())
         {
             if(!(((v1[i]+1)==v2[j])||((v1[i]-1)==v2[j])))
             {
                flag=1;
                break;
             }

         }
         if(flag==1)break;
     }
     if(flag==1)cout<<"YES\n";
     else cout<<"NO\n";

    return 0;
}

