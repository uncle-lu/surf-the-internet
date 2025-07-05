#include<iostream>
#include<vector>
#include<cstring>

const int N = 2 * 1e5 + 10;

int line[N];

int main()
{
	int T;
	long long int n, ans;
	std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for (int i = 1; i <= n; ++i) 
			std::cin >> line[i];

		std::vector<int>vis(2*n+10);
		ans = 0;
		long long int sum = 0;
		vis[sum] ++;

		for (int i = 1; i <= n; ++i) {
			sum ^= line[i];
			for (int j = 0; j*j <= 2*n; ++j) {
				if((sum xor (j*j)) < 2 * n)
				{
					ans += vis[(sum xor (j*j))];
				}
			}
			vis[sum] ++;
		}

		std::cout << (n + 1) * n / 2 - ans << std::endl;
	}

	return 0;
}
