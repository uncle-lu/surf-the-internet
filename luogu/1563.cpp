#include<iostream>
#include<string>
using namespace std;

const int N = 1e5+10;
int f[N];
string name[N];

int main() {
	int n, m, sit;
	cin >> n >> m;
	for(int i=n-1; i>=0; i--) {
		cin >> f[i] >> name[i];
		if(!f[i]) f[i] = 1;
		else f[i] = -1;
	}
	int flag, cnt;
	sit = n - 1;
	for(int i=1; i<=m; i++) {
		cin >> flag >> cnt;
		if(flag == 0) flag = 1;
		else flag = -1;
		sit = (sit + f[sit] * flag * (cnt%n) + n) % n;
	}
	cout << name[sit];
	return 0;
}
