#include<bits/stdc++.h>
using namespace std;
#define int long long
void inv  (int a, int b, int &x, int &y)
{
    if (a==0)
    {
        x=0;
        y=1;
        return;
    }
    inv((b%a), a, x, y);
    int z=x;
    int zz=y;
    x=zz-(b/a)*z;
    y=z;
}
main()
{
    int T;
    cin >> T;
    int x=0, y=0;
    for (int g=0; g<T; g++)
    {
        int a1, p, n;
        cin >> a1 >> p >> n;
        if (__gcd(a1, p)!=1)
        {
            cout << -1 << '\n';
            continue;
        }
        x=0;
        y=0;
        inv(a1, p, x, y);
        x%=p;//steps(below 3 only) to make x positive
        x+=p;
        x%=p;
        if (n&1)
        {
            cout << a1+(a1+x)*(n/2) << '\n';
        }
        else
        {
            cout << (a1+x)*(n/2) << '\n';
        }
    }
}
