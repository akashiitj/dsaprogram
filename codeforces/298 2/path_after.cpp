
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, t, d;
    cin >> a >> b >> t >> d;
    int ans = 0;
    while (t > 0) {
        ans += a;
        --t;
        a = min(b + (t - 1) * d, a + d);
    }
    cout << ans;
}
