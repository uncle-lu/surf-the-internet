#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 100010;
int v[N], p[N];
long long int ans;
bool vis[N], this_vis[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i] >> p[i];
		ans += p[i];
	}

	for (int i = 1; i <= n; ++i) {
		if(!vis[i])
		{
			memset(this_vis, false, sizeof(this_vis));
			this_vis[i] = true; vis[i] = true;
			int temp = i;
			while(!this_vis[v[temp]] && !vis[v[temp]])
			{
				temp = v[temp];
				this_vis[temp] = true; vis[temp] = true;
			}

			if(this_vis[v[temp]])
			{
				int mi = p[temp], t = v[temp];
				do{
					mi = min(mi, p[t]);
					t = v[t];
				}while(t != temp);
				ans -= mi;
			}
		}
	}

	cout << ans;
	return 0;
}
