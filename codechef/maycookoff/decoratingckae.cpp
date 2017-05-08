#include<bits/stdc++.h>
using namespace std;

#define LET(x, a)  __typeof(a) x(a)
#define TR(v, it) for(LET(it, v.begin()); it != v.end(); it++)
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
#define SET(x,y) memset(x,y,sizeof(x));
#define LL long long int
#define ULL unsigned LL
#define PII pair<int, int>

string s;
int cnt[26];
priority_queue<PII> pq, pq2;
int main()
{
    int t, i;
    cin >> t;
    while (t--)
    {
        cin >> s;
        pq = pq2;
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < (int)s.size(); i++)
        {
            cnt[s[i] - 'a']++;
        }
        for (i = 0; i < 26; i++)
        {
            pq.push(MP(cnt[i], i));
        }
        string ans = "";
        int p = -1;
        int fl;
        PII tmp;
        while (pq.top().first != 0)
        {
            fl = 0;
            if (p == pq.top().second)
            {
                tmp = pq.top();
                pq.pop();
                fl = 1;
                if (pq.top().first == 0)
                    break;
            }
            p = pq.top().second;
            int f = pq.top().first;
            ans += (char)(p + 'a');
            pq.pop();
            pq.push(MP(f - 1, p));
            if (fl)
            {
                pq.push(tmp);
            }
        }
        if (ans.size() != s.size())
        {
            printf("-1\n");
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
