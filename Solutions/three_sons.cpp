/*
https://codeforces.com/contest/120/problem/D
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> arr;
    vector<ll> row_prefix_sum(n, 0);
    vector<ll> col_prefix_sum(m, 0);
    ll sum_of_all = 0;
    REP(i, 0, n)
    {
        vector<ll> temp;
        REP(j, 0, m)
        {
            ll t;
            cin >> t;
            temp.push_back(t);
            row_prefix_sum[i] += t;
            col_prefix_sum[j] += t;
            sum_of_all += t;
        }
        arr.push_back(temp);
    }
    // Using prefix sum to calculate sum of any subsection in constant time instead of linear time
    REP(i, 1, n)
    {
        row_prefix_sum[i] += row_prefix_sum[i - 1];
    }
    REP(i, 1, m)
    {
        col_prefix_sum[i] += col_prefix_sum[i - 1];
    }

    ll ABC[3], abc[3];
    cin >> ABC[0] >> ABC[1] >> ABC[2];
    sort(ABC, ABC + 3);

    // If sum of all elements is not equal to sum of ABC
    if (sum_of_all != ABC[0] + ABC[1] + ABC[2])
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;

    // Col splitting
    REP(i, 1, m - 1)
    {
        REP(j, i + 1, m)
        {
            abc[0] = col_prefix_sum[i - 1];
            abc[1] = col_prefix_sum[j - 1] - col_prefix_sum[i - 1];
            abc[2] = col_prefix_sum[m - 1] - col_prefix_sum[j - 1];
            sort(abc, abc + 3);
            if (abc[0] == ABC[0] && abc[1] == ABC[1] && abc[2] == ABC[2])
            {
                ans++;
            }
        }
    }
    // Row splitting
    REP(i, 1, n - 1)
    {
        REP(j, i + 1, n)
        {
            abc[0] = row_prefix_sum[i - 1];
            abc[1] = row_prefix_sum[j - 1] - row_prefix_sum[i - 1];
            abc[2] = row_prefix_sum[n - 1] - row_prefix_sum[j - 1];
            sort(abc, abc + 3);
            if (abc[0] == ABC[0] && abc[1] == ABC[1] && abc[2] == ABC[2])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
