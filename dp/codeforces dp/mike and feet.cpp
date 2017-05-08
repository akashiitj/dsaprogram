#include<iostream>
#include<algorithm>
#include<vector>

#define F first
#define S second

using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], sz[MAXN], ans[MAXN], par[MAXN];
vector<pair<int, int> > e;

int getpar(int x)
{
    if(par[x] == -1)
        return x;
    return par[x] = getpar(par[x]);
}

void add(int x, int y, int e)
{
    x = getpar(x), y = getpar(y);
    if(sz[x] < sz[y])
        swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    ans[sz[x]] = max(ans[sz[x]], e);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i)
            e.push_back( {min(a[i], a[i - 1]), i - 1});
        ans[1] = max(ans[1], a[i]);
    }

    fill(par, par + MAXN, -1);
    fill(sz, sz + MAXN, 1);
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    for(int i = 0; i < n-1; i++)
        cout<<e[i].S<<" " <<e[i].S + 1<<"   "<<e[i].F<<"\n";
    for(int i = 0; i < n - 1; i++)
        add(e[i].S, e[i].S + 1, e[i].F);
    for(int i = n; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
