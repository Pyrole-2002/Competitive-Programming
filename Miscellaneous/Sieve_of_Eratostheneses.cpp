#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthenes(int n)
{
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
	for (int i = 2; (long long)i*i <= n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i*i; j <= n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

int main()
{
    long long a;
    cin >> a;
    vector<bool> is_prime = sieveOfEratosthenes(a);
    for (int i = 0; i <= a; i++)
    {
        if (is_prime[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}
