//author akashiitj
#include<bits/stdc++.h>

using namespace std;
typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define tk(x) scanf("%d",&x);
#define tk2(x,y) scanf("%d%d",&x,&y);
#define tkll(x) scanf("%lld",&x);
#define tk2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

void heapify(vector<int> &v,int n,int i)
{
    int left_child = (2*i)+1,right_child=(2*i)+2;
    if (left_child >= n)
        return;
    int min_index = i;
    if ( left_child < n and v[i] > v[left_child] ){
        min_index = left_child;
    }
    if ( right_child < n and v[min_index] > v[right_child] ){
        min_index =right_child;
    }
    if (i!= min_index)
    {
        swap(v[i],v[min_index]);
        heapify(v,n,min_index);
    }
}

void bubbleup(vector<int> &v,int i)
{
    int parent = (i-1)/2;
    if ( i==0 )
        return;
    if (v[parent] > v[i])
    {
        swap(v[i],v[parent]);
        bubbleup(v,parent);
    }
}

void insertnode(vector<int> &v,int val)
{
    v.push_back(val);
    bubbleup(v,v.size()-1);
}

int main()
{
    int n ;
    tk(n);
    vector<int> v(n);
    loop(i,0,n)
    {
        tk(v[i]);
    }
    for(int i=(n-1)/2;i>=0;i--)//rest is leaf node we dont need to heapify them
    {
        heapify(v,n,i);
    }
    int x;
    loop(i,0,n)
    {
        tk(x);
        insertnode(v,x);
    }
    loop(i,0,2*n)
      cout<< v[i] <<" ";


}
