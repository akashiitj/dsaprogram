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
  int t;
  double n,x=1.0;
  cin>>t;
  while(t--)
  {  x=1.0;
      cin>>n;
      loop(i,0,n)
      {
         x=x*((i+1)/n);
      }
      cout<<(2*n-1)*x*n<<endl;

  }
}



