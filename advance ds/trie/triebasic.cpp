
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

struct node
{
    int ifend;//1 means its ending point
    int prefixcount;//for finding number of string having this prefix
    node *child[26];//we are storing only lower case letter
};

node *head=NULL;

node *newnode()
{
    node *n=new node();
    n->ifend=0;
    n->prefixcount=0;
    loop(i,0,26)
    n->child[i]=NULL;
    return n;
}

void insert1(string s)
{
    node *current=head;
    current->prefixcount++;//it count total number of strings in trie

    loop(i,0,s.length())
    {
        if(current->child[s[i]-97]==NULL)
            current->child[s[i]-97]=newnode();
        current->child[s[i]-97]->prefixcount++;//this string s having prefix this one so add
        current=current->child[s[i]-97];//now current point to newly node
    }
    //current->prefixcount++;//for counting occurance of whole word only not prefix
    current->ifend=1;
}

int search1(string s)
{
    node *current=head;


    loop(i,0,s.length())
    {
        if(current->child[s[i]-97]==NULL)
            return 0;
        current=current->child[s[i]-97];
    }
    return (current->ifend==1);

}

int prefixc(string prefix)
{
    node *current=head;
    loop(i,0,prefix.length())
    {
        if(current->child[prefix[i]-97]==NULL)
            return 0;
        current=current->child[prefix[i]-97];

    }
    return current->prefixcount;
}



int main()
{
    //making trie
    head=newnode();

    //head node formed means empty trie gwt formed
    while(true)
    {
        string s,s1;
        cin>>s;
        if(s=="i")
        {
            cin>>s1;
            insert1(s1);
        }
        if(s=="s")
        {
            cin>>s1;
            cout<<search1(s1)<<endl;
        }

        if(s=="c")
        {
            cin>>s1;
            cout<<prefixc(s1)<<endl;

        }
    }


    return 0;
}

/*
//using matrix
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ifend 27
#define precoun 28
using namespace std;
int trie[1000][30];
static int cnt=1;
void insert_trie(string s)
{

    int cur=0;
    int k=0;
    while(trie[cur][s[k]-'a']!=0)
    {
        cur = trie[cur][s[k]-'a'];
        trie[cur][precoun]+=1;
        k++;
        if(k>=s.size())break;
    }
    if(k==s.size())
    {
        trie[cur][ifend]+=1;
    }
    else
    {
        while(k<s.size())
        {
            trie[cur][s[k]-'a']=cnt;
            cur = cnt;
            trie[cur][precoun]+=1;
            k++;
            cnt++;
        }
        trie[cur][ifend]+=1;
    }
    rep(i,0,15)
    {
        rep(j,0,6)
        cout<< trie[i][j]<<" ";
        cout<< trie[i][ifend]<<" "<<trie[i][precoun];
        cout<<"\n";
    }
}
int search_trie(string s)
{
    int cur=0;
    rep(i,0,s.size())
    {
        if(trie[cur][s[i]-'a']==0)return 0;
        cur = trie[cur][s[i]-'a'];
    }
    return (trie[cur][ifend]>=1);
}
int prefix_count(string s)
{
    int cur=0;
    rep(i,0,s.size())
    {
        if(trie[cur][s[i]-'a']==0)return 0;
        cur = trie[cur][s[i]-'a'];
    }
    return trie[cur][precoun];
}
int main()
{
    while(true)
    {
        string s,s1;
        cin>>s;
        if(s=="insert")
        {
            cin>>s1;
            insert_trie(s1);
        }
        if(s=="search")
        {
            cin>>s1;
            cout<<search_trie(s1)<<endl;
        }

        if(s=="count")
        {
            cin>>s1;
            cout<<prefix_count(s1)<<endl;

        }
    }
    return 0;

}
*/
