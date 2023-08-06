/*
https://codeforces.com/contest/872/problem/B
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

    ll n, k;
    cin >> n >> k;

    vector<ll> arr;
    REP(i, 0, n)
    {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }


    if (k == 1)
    {
        sort(arr.begin(), arr.end());
        cout << arr[0];
    }
    else if (k > 2)
    {
        sort(arr.begin(), arr.end());
        cout << arr[n - 1];
    }
    else
    {
        cout << max(arr[0], arr[n - 1]);
    }
    
    return 0;
}
