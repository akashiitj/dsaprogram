#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;
 ll w[100001],v[100001],p[100001],item[100001],solution[100001];
int main()
{
    int t;
    cin>>t;
    ull n,W,i,j,temp,amount,max_value=0;
    while(t--)
    {
        max_value=0;
        //  printf("Enter the number of items ::");
        //scanf("%d",&n);
        cin>>n>>W;

        for(i=0; i<n; i++)
        {

            cin>>w[i];
        }
      for(i=0; i<n; i++)
        cin>>v[i];
      for(i=0;i<n;i++)
      {
          amount=(W/w[i])*v[i];
          if(amount>max_value)max_value=amount;
      }

        cout<<max_value<<endl;

    }
    return 0;
}
