#include <stdio.h>
#define inf 111111111

char names[3][11] = {"none", "one", "both"};
int c[111111];
int n;

// best solution so far
int best;
int v1, v2, w1, w2;

// try the solution with these votes
void try_solution(int V1, int V2, int W1, int W2)
{
    if (!V1 || !V2 || !W1 || !W2) return; // ignore invalid votes
    c[V1]++, c[V2]++, c[W1]++, c[W2]++; // add votes
    // get max and min
    int mx = -inf, mn = inf;
    for (int i = 1; i <= n; i++)
    {
        if (mx < c[i]) mx = c[i];
        if (mn > c[i]) mn = c[i];
    }
    // get number of friends saved (0, 1 or 2), and compare with current best
    int ans = (mn < c[n-1] && c[n-1] < mx) + (mn < c[n] && c[n] < mx);
    if (best < ans)
    {
        best = ans;
        v1 = V1;
        v2 = V2;
        w1 = W1;
        w2 = W2;
    }
    c[V1]--, c[V2]--, c[W1]--, c[W2]--; // relinquish votes
}

int main()
{
    c[0] = -1; // sentinel
    int z;
    scanf("%d", &z);
    while (z--)
    {
        // collect votes
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) c[i] = 0;
        for (int V = 2*(n-2); V--;)
        {
            int v;
            scanf("%d", &v);
            c[v]++;
        }
        // get highest and next highest from first n-2 people.
        int mx = 0, nx = 0;
        for (int i = 1; i <= n-2; i++)
        {
            if (c[mx] <= c[i])
            {
                nx = mx;
                mx = i;
            }
            else if (c[nx] <= c[i])
            {
                nx = i;
            }
        }
        // try all 4 choices
        best = -1;
        try_solution(mx,  n, mx, n-1);
        try_solution(mx, nx, mx, n-1);
        try_solution(mx,  n, mx, nx);
        try_solution(mx, nx, mx, nx);
        // print answer
        printf("%s\n%d %d\n%d %d\n", names[best], v1, v2, w1, w2);
    }
}
