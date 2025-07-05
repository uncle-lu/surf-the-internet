#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int N = 110;
string name[N];
int line[N], ans[N][N];

int main() {
	int n, k;
	cin >> k >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> name[i];
	}
	
	string temp;
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> temp;
			for (int t = 1; t <= n; ++t)
				if(temp == name[t]) {
					line[j] = t;
					break;
				}
		}
		for (int j = 1; j <= n; ++j) {
			bool up = false;
			for (int t = j - 1; t >= 1; --t) {
				if(name[line[t]] > name[line[t+1]])
					up = true;
				if(up) {
					ans[line[j]][line[t]] = 1;
					ans[line[t]][line[j]] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(i == j) {
				cout << 'B';
				continue;
			}
			if(ans[i][j]==-1)
				cout << '?';
			else
				cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
