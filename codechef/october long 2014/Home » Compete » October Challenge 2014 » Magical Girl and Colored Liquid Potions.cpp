#include<bits/stdc++.h>
using namespace std;

int main()
{  //cout<<max(2,2);
    //vector<long long> v;
    ios_base::sync_with_stdio(false);
    long long t,r,g,b,m,er=-1,eg=-1,eb=-1;
    long long i,x;
    cin>>t;
    while(t>0)
    {  cin>>r>>g>>b>>m;
       er=-1,eg=-1,eb=-1;
       for(i=0;i<r;i++)
       {cin>>x;
       if(er<x)er=x;
       }
       for(i=0;i<g;i++)
       {cin>>x;
       if(eg<x)eg=x;
       }
       for(i=0;i<b;i++)
       {cin>>x;
       if(eb<x)eb=x;
       }
       // cout<<er<<" er "<<eg<<" eg "<<eb<<" eb "<<endl;
       long long s=max(max(er,eb),eg);
       while(m>0){
       if(er>=max(eb,eg))
       {
           er=er/2;
           eb++;
           eg++;
         //  cout<<"er    "<<er<<" er "<<eg<<" eg "<<eb<<" eb "<<endl;
       }
       else if(eb>=max(er,eg))
       {
           eb=eb/2;
           er++;
           eg++;
           // cout<<"eb    "<<er<<" er "<<eg<<" eg "<<eb<<" eb "<<endl;
       }
        else if(eg>=max(er,eb))
       {
           eg=eg/2;
           eb++;
           er++;
         //  cout<<"eg    "<<er<<" er "<<eg<<" eg "<<eb<<" eb "<<endl;
       }

       if(s>max(max(er,eb),eg))s=max(max(er,eb),eg);
       m--;
       }

       cout<<s<<endl;
        t--;

    }
}



