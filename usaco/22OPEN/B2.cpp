#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, p;
	char method;
	cin >> n;
	vector<int>L, G;
	for (int i = 0; i < n; ++i) {
		cin >> method >> p;
		if(method == 'L')
			L.push_back(p);
		else
			G.push_back(p);
	}
	sort(L.begin(), L.end());
	sort(G.begin(), G.end());

	int i = 0, j = 0, l_len = L.size(), g_len = G.size();
	int ans = min(l_len, g_len);

	while(i < l_len && j < g_len)
	{
		if(L[i] < G[j])
		{
			ans = min(ans, i + g_len - j);
			i++;
		}
		else
		{
			ans = min(ans, i + g_len - j - 1);
			j++;
		}
	}

	cout << ans;
	return 0;
}
