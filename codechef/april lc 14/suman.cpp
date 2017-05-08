#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

typedef long long ll;

#define FOR(i,n) for(ll i=0;i<n;i++)
#define FORS(i,x,n) for(ll i=x;i<=n;i++)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;


inline ll read_long(ll &x){
	x=0;int sign,ch;
	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF) ch=getchar();
	if (ch=='-')
		sign=-1,ch=getchar();
	else sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar())>='0' && ch<='9');
	x*=sign;
	return 1;
}

inline int read_int(int &x){
	x=0;int sign,ch;
	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF) ch=getchar();
	if (ch=='-')
		sign=-1,ch=getchar();
	else sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar())>='0' && ch<='9');
	x*=sign;
	return 1;
}

int main()
{
    ll t;
    read_long(t);
    ll N,R,L;
    ll ans=0;
    while(t>0){
        read_long(N);
        read_long(L);
        read_long(R);
        ans=0;
        ll f=1;
        ll n=0;
        ll s1=0;
        int flag=0;
        if(N==1) flag=1,cout<<R-L+1<<endl;
        else{
        FORS(i,L,R)
        {
            f=1;
            s1=0;
            n=R-i+1;
            //cout<<"n is "<<n<<endl;
            //f1=n;
            for(ll j=1;j<N;j++)
                {
                    s1+=(f*(n+(j-1)))/j;
                    //cout<<"hello os "<<((n+(j-1))/j)<<endl;
                    f=s1;
                    //cout<<"f is "<<f<<endl;
                }
                //cout<<"s1 is "<<s1<<endl;
                ans+=s1+1;
                //cout<<"ans is "<<ans<<endl;
        }
        }

        if(flag==0) cout<<ans<<endl;
        t--;
    }

}
