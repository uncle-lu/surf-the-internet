#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1500*1503;
vector<int>edge[N];
int Fa[N], n, d[N];
long long int sum;
char maps[1501][1501];
int rline[N], dline[N];

int trans_num(int x, int y)
{
	if(x == n)
		return y;
	if(y == n)
		return n + x;
	return 2*n + x*n + y;
}

void add_edge(int x, int y)
{
	edge[x].push_back(y);
	Fa[y] = x;
	return ;
}

void DFS(int x, int val)
{
	sum = sum - d[x] + val;
	d[x] = val;
	for(auto i : edge[x]){
		DFS(i, val);
	}
	return ;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> maps[i] >> rline[i];
	for (int i = 0; i < n; ++i) 
		cin >> dline[i];

	for (int i = n-1; i >= 0; i--)
		for (int j = n-1; j >= 0; j--)
			if(maps[i][j] == 'D')
				add_edge(trans_num(i+1, j), trans_num(i, j));
			else
				add_edge(trans_num(i, j+1), trans_num(i, j));

	for (int i = 0; i < n*2; ++i) 
		if(i < n)
		{
			DFS(i, dline[i]);
			sum -= dline[i];
		}
		else
		{
			DFS(i, rline[i-n]);
			sum -= rline[i-n];
		}

	cout << sum << endl;

	int q, x, y;
	cin >> q;
	while(q--)
	{
		cin >> x >> y;
		x--; y--;
		if(maps[x][y] == 'D')
		{
			maps[x][y] = 'R';
			edge[trans_num(x+1, y)].erase(find(edge[trans_num(x+1, y)].begin(), edge[trans_num(x+1, y)].end() ,trans_num(x, y)));
			edge[trans_num(x, y+1)].push_back(trans_num(x, y));
			Fa[trans_num(x, y)] = trans_num(x, y+1);
			DFS(trans_num(x, y), d[trans_num(x, y+1)]);
		}
		else
		{
			maps[x][y] = 'D';
			edge[trans_num(x, y+1)].erase(find(edge[trans_num(x, y+1)].begin(), edge[trans_num(x, y+1)].end(), trans_num(x, y)));
			edge[trans_num(x+1, y)].push_back(trans_num(x, y));
			Fa[trans_num(x, y)] = trans_num(x+1, y);
			DFS(trans_num(x, y), d[trans_num(x+1, y)]);
		}
		cout << sum << endl;
	}

	return 0;
}
