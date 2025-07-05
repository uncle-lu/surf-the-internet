#include<iostream>
#include<vector>
using namespace std;

const int N = 100010;
vector<int>maps[N];
vector<int>A(N);

void DFS(int x, int sit)
{
	if(A[x])return ;
	A[x] = sit;
	for(auto i : maps[x]) {
		DFS(i, sit);
	}
	return ;
}
int main()
{
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		maps[y].push_back(x);
	}
	for (int i = n; i >= 1; i--) {
		DFS(i, i);
	}
	for (int i = 1; i <= n; ++i) {
		cout << A[i] << ' ';
	}
	return 0;
}
