#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define loop(i, a, b)  for(int i=a;i<b;i++)
ll mod1(ll a,ll b)
{
    return a%b;
}

main()
{  std::ios_base::sync_with_stdio(false);
  int t,n,x;
  cin>>t;
  while(t--)
  {
      cin>>n;
      loop(i,0,n)
      {
          cin>>x>>x;
      }
      x=n;
      loop(i,0,n)
      {
          x=x^i;
      }
      cout<<x<<endl;
  }
}


