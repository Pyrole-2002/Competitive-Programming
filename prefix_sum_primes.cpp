/*
https://codeforces.com/contest/1149/problem/A
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

ll swap(ll a, ll b)
{
    ll tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll len = 0;
    cin >> len;
    ll arr[len];
    ll one = 0;
    ll two = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    ll final[len];
    for (int i = 0; i < len; i++)
    {
        if ((i == 0) && (two != 0))
        {
            final[i] = 2;
            two--;
        }
        else if ((i == 1) && (one != 0))
        {
            final[i] = 1;
            one--;
        }
        else
        {
            if (two != 0)
            {
                final[i] = 2;
                two--;
            }
            else
            {
                final[i] = 1;
                one--;
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        cout << final[i] << " ";
    }
    cout << endl;

    return 0;
}
