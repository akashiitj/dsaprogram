#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    if(N % 2 == 0)
        cout << "NO\n";
    else
    {
        cout << "YES\n";

        cout << 4*(N-1) + 2 << " " << (2 * (N-1) * (N-1)) + (3 * (N-1)) + 1 << endl;
        cout << 1 << " " << 2 << "\n";

        for(int i = 1; i < N; i++)
            cout << 2 << " " << 2 + i << endl;

        for(int i = 3; i <= N+1; i++)
            for(int j = N+2; j <= 2*N; j++)
                cout << i << " " << j << endl;

        for(int j = N+2; j <= 2*N; j += 2)
            cout << j << " " << j + 1 << endl;

        for(int i = 2*N + 1; i <= 3*N - 1; i++)
            cout << 1 << " " << i << endl;

        for(int i = 2*N + 1; i <= 3*N-1; i++)
            for(int j = 3*N; j <= 4*N-2; j++)
                cout << i << " " << j << endl;

        for(int j = 3*N; j <= 4*N-2; j+=2)
            cout << j << " " << j+1 << endl;
    }
    return;
}

int main()
{
    solve();

    return 0;
}
