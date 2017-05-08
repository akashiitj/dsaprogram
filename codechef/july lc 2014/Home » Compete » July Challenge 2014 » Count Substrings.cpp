#include<iostream>
using namespace std;
 //count no of  1 and then no of ways of seleting 2 1 from given no +no of 1
main()
{  unsigned long long t,los;

    cin>>t;
    while(t>0)
    { unsigned long long  c=0;
      cin>>los;
      string a;
     cin>>a;
     for(unsigned long long i=0;i<los;i++)
        if(a[i]=='1')c++;

     if(c>=2)cout<<((c*(c-1))/2)+c<<endl;
     else cout<<c<<endl;
     t--;
    }
}
