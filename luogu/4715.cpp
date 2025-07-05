#include<iostream>
#include<algorithm>
using namespace std;

const int N = (1<<8)+10;

int tree[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1<<n; i <= (1<<(n+1))-1; ++i) {
		cin >> tree[i];
	}

	for (int i = (1<<n)-1; i>=1; --i)
		tree[i] = max(tree[2*i] , tree[2*i+1]);
	
	int ans = min(tree[2], tree[3]);

	for (int i=1<<n; i <= (1<<(n+1))-1; i++)
		if(tree[i] == ans)
		{
			cout << i - (1<<n) + 1;
			break;
		}

	return 0;
}
