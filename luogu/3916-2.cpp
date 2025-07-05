#include<iostream>
#include<vector>
using namespace std;

void DFS(int x, int sit, vector<vector<int> > &maps, vector<int> &A)
{
	if(A[x])return ;
	A[x] = sit;
	for(auto i : maps[x]) {
		DFS(i, sit, maps, A);
	}
	return ;
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int> >maps(n+1);
	vector<int>A(n+1);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		maps[y].push_back(x);
	}
	for (int i = n; i >= 1; i--) {
		DFS(i, i, maps, A);
	}

	for (int i = 1; i <= n; ++i) {
		cout << A[i] << ' ';
	}

	return 0;
}

