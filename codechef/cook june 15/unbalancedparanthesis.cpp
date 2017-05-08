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
int main()
{
    int t, k, i;
    cin >> t;
    while (t--)
    {
        vector<int> open, close;
        cin >> s >> k;
        int n = s.size();
        int csc = 0;
        int valid = 1;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '(')
                csc ++;
            else
                csc --;
            if (csc < 0)
            {
                valid = 0;
                break;
            }
        }
        if (csc != 0)
            valid = 0;
        if (!valid)
        {
            if (k == 1)
            {
                cout << s << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }
        for (i = 0; i < n; i++)
        {
            if (i == 0 || s[i] != s[i - 1])
            {
                if (s[i] == '(')
                    open.PB(i);
                else
                    close.PB(i);
            }
        }
        reverse(open.begin(), open.end());
        if (k > open.size() + close.size())
        {
            cout << -1 << endl;
            continue;
        }
        else if (k <= close.size())
        {
            s.erase(s.begin() + close[k - 1]);
        }
        else
        {
            k -= close.size();
            s.erase(s.begin() + open[k - 1]);
        }
        cout << s << endl;
    }
    return 0;
}
