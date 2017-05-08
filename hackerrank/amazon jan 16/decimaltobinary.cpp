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

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);






void dec_to_binary(int number,int &count1) {
	int remainder;

	if(number <= 1) {
		if(number==1)
        count1++;
		return;
	}

	remainder = number%2;
	dec_to_binary(number >> 1,count1);
	if(remainder==1)
	count1++;

}



bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
   if(i.first != j.first) return i.first > j.first;
    return i.second > j.second;
}

void swap_array( vector<int> a) {

    int c;
    int a_siz =a.size();
    vector<pii > v;
    for(int i=0;i<a_siz;i++)
    {
         c=0;
         dec_to_binary(a[i],c);
        v.pb(mp(c,a[i]));

    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<a_siz;i++)
        cout<<v[i].second<<"\n";


}
int main() {


    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }

    swap_array(_a);

    return 0;
}
