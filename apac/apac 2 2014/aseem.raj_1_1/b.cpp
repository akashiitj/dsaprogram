/*
Author: aseemraj
Problem: C
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 10000;
int ans[10005][10005];

int main()
{
    int np, ne, nt, test, x, m;
    ll a, b, g, p, q;
    vector<int> tp, te, tt;
    cin>>test;
    for(int t = 1; t <= test; t++)
    {
        tp.clear();
        te.clear();
        tt.clear();
        memset(ans,0,sizeof(ans));
        cin>>np>>ne>>nt;

        for(int i = 0; i < np; i++)
        {
            cin>>x;
            tp.push_back(x);
        }

        for(int i=0; i<ne; i++)
        {
            cin>>x;
            te.push_back(x);
        }

        for(int i=0; i<nt; i++)
        {
            cin>>x;
            tt.push_back(x);
        }

        for(int i=0; i<ne; i++)
        {
            for(int j=0; j<nt; j++)
            {
                g = __gcd(te[i], tt[j]);
                a = te[i]/g;
                b = tt[j]/g;
                ans[a][b] = i+1;
            }
        }
        
        cin>>m;
        cout<<"Case #"<<t<<":\n";
        bool found;
        while(m--)
        {
            found = 0;
            cin>>p>>q;
            if(p==1 && q==1)
            {
                cout<<"No"<<endl;
                continue;
            }
            for(int i=0; i<np; i++)
            {
                if(!found)
                {
                    for(int j=0; j<ne; j++)
                    {
                        a = p*te[j];
                        b = q*tp[i];
                        g = __gcd(a, b);
                        a /= g;
                        b /= g;
                        if(a<=MAXN && b<=MAXN)
                        {
                            if(ans[a][b] && ans[a][b] != j+1)
                            {
                                found = 1;
                                break;
                            }
                        }
                    }
                }
                else break;
            }
            if(found)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
