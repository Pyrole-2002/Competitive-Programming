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
#define MOD (int)(1e9 + 7)

void matmul(ll res[2][2], ll a[2][2], ll b[2][2])
{
    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            ll sum = 0;
            REP(k, 0, 2)
            {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
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
    return result[0][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        ll n;
        cin >> n;
        if (n == -1)
            break;
        cout << "Fibonacci " << n << " : " << fib(n) << endl;
    }

    return 0;
}
