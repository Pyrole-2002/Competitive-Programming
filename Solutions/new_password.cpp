/*
https://codeforces.com/contest/770/problem/A
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    long long temp = 0;
    REP(i, 0, n)
    {
        if (temp >= k)
        {
            temp = 0;
        }
        cout << (char)('a' + temp++);
    }
    cout << '\n';

    return 0;
}
