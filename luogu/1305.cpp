#include<iostream>
using namespace std;

struct node{
	int l, r;
};
node line[30];

void DFS(int x)
{
	printf("%c", x + 'a');
	if(line[x].l != -1)
		DFS(line[x].l);
	if(line[x].r != -1)
		DFS(line[x].r);
	return ;
}

int main()
{
	int n, root; char x, l, r;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> l >> r;
		line[x - 'a'].l = l == '*' ? -1 : l - 'a';
		line[x - 'a'].r = r == '*' ? -1 : r - 'a';
		if ( i == 0 )
			root = x - 'a';
	}
	DFS(root);
	return 0;
}
