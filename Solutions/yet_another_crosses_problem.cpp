/*
https: // codeforces.com/contest/1194/problem/B
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = int64_t;
#define INF (int)((1ll << 31) - 1)
#define REP(i, start, end) for (ll i = start; (i) < (ll)(end); (i)++)
#define MOD (int)(1e9 + 7)

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll mod(ll n, ll m)
{
    return (((n % m) + m) % m);
}

void swap(ll &a, ll &b)
{
    ll temp = a;
    a = b;
    b = temp;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> arr;
        vector<ll> rows_black(n, 0);
        vector<ll> cols_black(m, 0);
        REP(i, 0, n)
        {
            vector<ll> temp;
            REP(j, 0, m)
            {
                char c;
                cin >> c;
                if (c == '*')
                {
                    rows_black[i]++;
                    cols_black[j]++;
                }
                temp.push_back(c);
            }
            arr.push_back(temp);
        }

        ll ans = INF;
        REP(i, 0, n)
        {
            REP(j, 0, m)
            {
                ll temp = n - rows_black[i] + m - cols_black[j];
                if (arr[i][j] == '.')
                {
                    temp--;
                }
                ans = min(ans, temp);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
