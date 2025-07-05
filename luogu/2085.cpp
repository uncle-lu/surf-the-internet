#include<iostream>
#include<queue>
using namespace std;

const int N = 10010;
int a[N], b[N], c[N];

struct node{
	int x, sit;
	friend bool operator<(const node i, const node j)
	{
		int i_val = a[i.sit] * i.x * i.x + b[i.sit] * i.x + c[i.sit];
		int j_val = a[j.sit] * j.x * j.x + b[j.sit] * j.x + c[j.sit];
		return i_val > j_val;
	}
};
priority_queue<node>qu;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
	{
		cin >> a[i] >> b[i] >> c[i];
		qu.push((node){1, i});
	}

	for (int i = 0; i < m; ++i) {
		node now = qu.top();
		qu.pop();
		int val = a[now.sit] * now.x * now.x + b[now.sit] * now.x + c[now.sit];
		cout << val << ' ';
		qu.push((node){now.x+1, now.sit});
	}

	return 0;
}
