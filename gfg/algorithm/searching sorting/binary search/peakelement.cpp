/*

The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Logn).
We basically ignore half of the elements just after one comparison.
1) Compare x with the middle element.
2) If x matches with middle element, we return the mid index.
3) Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
4) Else (x is smaller) recur for the left half.

Algorithmic Paradigm: Divide and Conquer

 Theta(Logn)

*/
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int a[100];
int n;

int pe(int i,int j)
{
    int m=(i+j)/2;
    if((m==0||a[m-1]<=a[m])&&(m==n-1||a[m+1]<=a[m]))//if middle element is peak element
    return m;

    if(m>0&&a[m-1]>a[m])
        return pe(i,m-1);
    else return pe(m+1,j);
}

int main()
{   int l,h,m,ansi,x;
    le(n);
    loop(i,0,n)
    le(a[i]);
    cout<<a[pe(0,n-1)]<<"\n";
    return 0;
}



