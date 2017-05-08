//http://www.exploringbinary.com/powers-of-two-in-the-josephus-problem/comment-page-1/#comment-9386
//http://en.wikipedia.org/wiki/Josephus_problem

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)

ll po2a[65];

main()
{   po2a[0]=1;
    loop(i,1,65)
     po2a[i]=po2a[i-1]*2;
 int t;
 cin>>t;
   while(t--){
    ll n;
    cin>>n;

    ll x=0;
    loop(i,1,65)
    {
        if(n>=po2a[i-1]&&n<po2a[i])
        {
            x=i-1;
            break;
    }}
    cout<<2*(n-po2a[x])+1<<endl;
}
}
