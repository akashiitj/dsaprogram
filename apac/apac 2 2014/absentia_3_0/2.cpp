#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstring>
#include <string>
#include <bitset>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <list>
#include <deque>

#define reps(i,a,b) for (int i=a;i<b;i++)
#define rep(i,b) for (int i=0;i<b;i++)
#define pb push_back
#define rz resize
#define vi vector<int>
#define vii vector<vector<int> >
#define mod 1000000007
#define oo 100000000

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
vector<string> vp;

void _allparenthesis(int pos, int n, int open, int close, string str)
{
  //static char str[50];

  if(close == n)
  {
    vp.push_back(str);
    // printf("%s \n", str);
    return;
  }
  else
  {
    if(open > close) {
        //str.push_back(')');
        _allparenthesis(pos+1, n, open, close+1, str+")");
        //str.resize(str.size()-1);
    }
    if(open < n) {
       //str.push_back('(');
       _allparenthesis(pos+1, n, open+1, close, str+"(");
    }
  }
}

void allparenthesis(int n)
{
  string str;
  if(n > 0)
     _allparenthesis(0, n, 0, 0, str);
  return;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int cases,n,k;
    cin>>cases;
    for (int t=1; t <= cases; t++)
    {

        cin>>n>>k;
        // for (int i=1;i<=10;i++)
        // {
        //     vp.clear();
        //     allparenthesis(i);
        //     cout<<vp.size()<<'\n';
        // }

        cout<<"Case #"<<t<<": ";
        // cout<<vp.size()<<'\n';
        vp.clear();
        allparenthesis(n);
        sort(vp.begin(), vp.end());
        // for (int i=0;i<vp.size();i++)
        //     cout<<vp[i].size()<<'\n';
        if (k <= vp.size())
            cout<<vp[k-1]<<'\n';
        else
            cout<<"Doesn't Exist!\n";
    }
return 0;
}
