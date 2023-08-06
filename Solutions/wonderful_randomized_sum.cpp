/*
https://codeforces.com/contest/33/problem/C
*/

/*
Array:    a a a a a  b b b  c c c c c c c
We need to minimize the sum of group "a" and group "c"
so that on inverting it and adding it will give most profit.
Equivalently make the group "b" such that it has the max possible sum.
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

    ll n;
    cin >> n;
    vector<ll> arr;
    ll sum = 0;
    REP(i, 0, n)
    {
        ll temp;
        cin >> temp;
        sum += temp;
        arr.push_back(temp);
    }

    // find a continous subsection having the maximum possible sum
    ll max_mid_sum = 0;
    ll mid_sum = 0;
    REP(i, 0, n)
    {
        mid_sum += arr[i];
        max_mid_sum = max(max_mid_sum, mid_sum);
        if (mid_sum < 0)
        {
            mid_sum = 0;
        }
    }

    // calculate sum of prefix and suffix
    ll prefix_suffix = sum - max_mid_sum;
    prefix_suffix *= -1;

    cout << prefix_suffix + max_mid_sum << endl;

    return 0;
}
