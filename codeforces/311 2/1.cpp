#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int N, mx1, mx2, mx3, mn1, mn2, mn3;
    cin >> N;
    cin >> mn1 >> mx1;
    cin >> mn2 >> mx2;
    cin >> mn3 >> mx3;

    int a1 = min(N - (mn2+mn3), mx1);
    int a2 = min((N-a1) - (mn3), mx2);
    int a3 = min(N - (a1+a2), mx3);
    cout << a1 << " " << a2 << " " << a3 << endl;
    return;
}

int main()
{
    solve();
    return 0;
}
