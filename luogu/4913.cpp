#include<iostream>
using namespace std;

struct node{
	int l, r;
};
node line[1000010];
int ans;

void DFS(int x, int dep)
{
	if(dep > ans)
		ans = dep;
	if(line[x].l!=0)
		DFS(line[x].l, dep+1);
	if(line[x].r!=0)
		DFS(line[x].r, dep+1);
	return ;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> line[i].l >> line[i].r;

	DFS(1, 1);

	cout << ans;

	return 0;
}
