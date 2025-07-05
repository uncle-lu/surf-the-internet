#include<iostream>
#include<cstring>
using namespace std;

const int N = 305;
int r[N][N], ans[N], mx[N], mi[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) 
		for (int j = i; j < n; ++j) 
			cin >> r[i][j];
	for (int i = 0; i < n; ++i) {
		mx[i] = -1e9;
		mi[i] = 1e9;
	}

	ans[0] = 0; mx[0] = 0; mi[0] = 0;

	for (int i = 1; i < n; ++i) {
		int temp = ans[i-1] + r[i-1][i];
		bool flag = true;

		for (int j = 0; j < i; ++j) {
			if(max(mx[j], temp) - min(mi[j], temp) != r[j][i])
			{
				flag = false;
				break;
			}
		}
		
		if(!flag)
			temp = ans[i-1] - r[i-1][i];

		for (int j = 0; j <= i; ++j) {
			mx[j] = max(mx[j], temp);
			mi[j] = min(mi[j], temp);
		}
		ans[i] = temp;
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';

	return 0;
}
