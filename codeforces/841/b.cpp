#include<iostream>

const long long int mod = 1e9 + 7;

int main()
{
	int T;
	std::cin >> T;
	while(T--)
	{
		long long int n, sum = 0;
		std::cin >> n;
		sum = (((n*(n+1)) % mod) * (4 * n - 1) % mod) * 337 % mod;
		std::cout << sum << std::endl;
	}

	return 0;
}
