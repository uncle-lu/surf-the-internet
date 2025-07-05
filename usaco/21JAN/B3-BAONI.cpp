#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>line, h;
int n;
long long int ans;
bool vis[30];

void DFS(int x)
{
	if(x >= n)
	{
		ans++;
		return ;
	}

	for (int i = 0; i < n; ++i) {
		if(line[x] > h[i])break;
		if(vis[i])continue;
		vis[i] = true;
		DFS(x+1);
		vis[i] = false;
	}

	return ;
}

int main()
{
	int temp;
	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		cin >> temp;
		line.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		h.push_back(temp);
	}

	sort(line.rbegin(), line.rend(), greater<int>());
	sort(h.rbegin(), h.rend());

	DFS(0);

	cout << ans;
	return 0;
}
