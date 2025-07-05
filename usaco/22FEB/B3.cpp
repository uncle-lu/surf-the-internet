#include<iostream>
#include<cstring>
using namespace std;

bool maps[4][26], vis[4], flag;
char line[10];
int len;

void DFS(int x)
{
	if(x>len)
	{
		flag = true;
		return ;
	}
	for (int i = 0; i < 4; ++i) {
		if(vis[i])continue;
		if(!maps[i][line[x] - 'A'])continue;
		vis[i] = true;
		DFS(x+1);
		vis[i] = false;
		if(flag) return ;
	}

	return ;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < 4; ++i) {
		char temp;
		for (int j = 0; j < 6; ++j) {
			cin >> temp;
			maps[i][ temp-'A' ] = true;
		}
	}
	while(T--)
	{
		memset(vis, false, sizeof(vis));
		flag = false;
		cin >> line;
		len = strlen(line)-1;
		DFS(0);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
