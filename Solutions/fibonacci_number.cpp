/*
https://codeforces.com/problemset/problem/193/E
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = int64_t;
#define INF (int)((1ll << 31) - 1)
#define REP(i, start, end) for (ll i = start; (i) < (ll)(end); (i)++)
#define MOD (ll)(1e13)

ll mod(ll n, ll m)
{
    return (((n % m) + m) % m);
}

ll binmul(ll a, ll b, ll m)
{
    a = mod(a, m);
    ll res = 0;
    while (b)
    {
        if (b & 1)
        {
            res = mod(res + a, m);
        }
        a = mod(a + a, m);
        b >>= 1;
    }
    return res;
}

void matmul(ll res[2][2], ll a[2][2], ll b[2][2])
{
    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            ll sum = 0;
            REP(k, 0, 2)
            {
                sum += binmul(a[i][k], b[k][j], MOD);
            }
            res[i][j] = mod(sum, MOD);
        }
    }
}

ll fib(ll n)
{
    ll base[2][2] = {
        {1, 1},
        {1, 0}
    };

    ll result[2][2] = {
        {1, 0},
        {0, 1}
    };
    while(n)
		{
        if (n & 1)
        {
            ll tmp[2][2];
            REP(i, 0, 2)
            {
                REP(j, 0, 2)
                {
                    tmp[i][j] = result[i][j];
                }
            }
            matmul(result, base, tmp);
        }
        ll tmp[2][2];
        REP(i, 0, 2)
        {
            REP(j, 0, 2)
            {
                tmp[i][j] = base[i][j];
            }
        }
        matmul(base, tmp, tmp);
        n >>= 1;
    }
    return mod(result[0][1], MOD);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll f;
	cin >> f;
	double x = log10f(sqrt(5) * f) / log10f((1 + sqrt(5)) / 2);
	ll n = (ll)ceil(x);

	if (fib(n) == f)
	{
		cout << n << '\n';
	}
	else if (fib(n + 1) == f)
	{
		cout << n + 1 << '\n';
	}
	else if (fib(n - 1) == f)
	{
		cout << n - 1 << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}

	return 0;
}

// TODO: Consider modulo 1e13
