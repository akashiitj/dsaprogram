#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define getcx       getchar_unlocked
#define putcx       putchar_unlocked
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
#define ft          first
#define sc          second
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

#ifdef TRACE
template<class T> ostream& printContainer(ostream &o,const T &c){
    tr(it,c){
        o<<*it<<' ';
    }
    return o;
}

template<class T> ostream& operator<<(ostream &o,const vector<T> &c){return printContainer(o,c);}
template<class T> ostream& operator<<(ostream &o,const deque<T> &c){return printContainer(o,c);}
template<class T> ostream& operator<<(ostream &o,const list<T> &c){return printContainer(o,c);}
template<class T> ostream& operator<<(ostream &o,const set<T> &c){return printContainer(o,c);}
template<class T> ostream& operator<<(ostream &o,const uset<T> &c){return printContainer(o,c);}
template<class T> ostream& operator<<(ostream &o,const multiset<T> &c){return printContainer(o,c);}
template<class T,class V> ostream& operator<<(ostream &o,const map<T,V> &c){return printContainer(o,c);}
template<class T,class V> ostream& operator<<(ostream &o,const umap<T,V> &c){return printContainer(o,c);}
template<class T,class V> ostream& operator<<(ostream &o,const pair<T,V> &c){return (o<<"("<<c.ft<<","<<c.sc<<")");}

#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace(x)
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

static int r[3000][3000][13];
struct TwoDRMQ{
    int (*a)[3001];
//    vector<vector<vector<int> > > r;
    int N;
    vector<int> p;
    TwoDRMQ(int (*a)[3001],int N):a(a),N(N){
        preprocess();
    }
    void preprocess(){
        p.push_back(1);
        while(p.back()<N)
            p.push_back(p.back()*2);

//        r.resize(N);
        int sz=p.size();
        int i,j,t;
//        rep(i,0,N){
//            r[i].resize(N);
//            rep(j,0,N){
//                r[i][j].resize(sz);
//            }
//        }

        rep(i,1,N+1){
            rep(j,1,N+1){
                r[i][j][0]=a[i][j];
            }
        }
        
        rep(t,1,sz+1){
            int K=(1<<t);
            rep(i,1,N+2-K){
                rep(j,1,N+2-K){
                    int k=i+K/2,l=j+K/2;
                    int ans=0;
                    ans=max(ans,r[i][j][t-1]);
                    ans=max(ans,r[i][l][t-1]);
                    ans=max(ans,r[k][j][t-1]);
                    ans=max(ans,r[k][l][t-1]);
                    r[i][j][t]=ans;
                }
            }
        }
    }
    int query(int i,int j,int K){
        int ans=0;
        int k=i+K,l=j+K;
        int idx=upper_bound(p.begin(), p.end(), K)-1-p.begin();
        int diff=p[idx];
        k-=diff;l-=diff;
        ans=max(ans,r[i][j][idx]);
        ans=max(ans,r[i][l][idx]);
        ans=max(ans,r[k][j][idx]);
        ans=max(ans,r[k][l][idx]);
        return ans;
    }
};

int main() {
    int T,i,j;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    for(int case_no=1;case_no<=T;case_no++) {
        static int a[3001][3001];
        int N,K,C,X;
        cin>>N>>K>>C>>X;
        vector<ll> A(N+1),B(N+1);
        rep(i,1,N+1)
            cin>>A[i];
        rep(i,1,N+1)
            cin>>B[i];

        rep(i,1,N+1){
            rep(j,1,N+1){
                a[i][j]=(A[i]*i+B[j]*j+C)%X;
            }
        }

        #ifdef TRACE
        rep(i,1,N+1){
            rep(j,1,N+1){
                cerr<<a[i][j]<<" ";
            }
            cerr<<endl;
        }
        #endif

        TwoDRMQ r(a,N);

        ll ans=0;
        rep(i,1,N+2-K){
            rep(j,1,N+2-K){
                int m=r.query(i,j,K);
                ans+=m;
            }
        }

//-------------------------------------------------------

        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %lld\n",case_no,ans);
        cout<<ans_string;
    }
    return 0;
}

