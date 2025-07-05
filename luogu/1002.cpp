#include <cstdio>

const int N = 30;
long long int f[N][N];
int x_turn[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int y_turn[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int main() {
	int x, y, a, b;
	scanf("%d %d %d %d", &x, &y, &a, &b);
	f[0][0] = 1;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if(i == 0 && j == 0)continue;
			bool flag = true;
			for (int t = 0; t < 9; t++) 
				if(a+x_turn[t] == i && b + y_turn[t] == j) {
					flag = false;
					break;
				}
			if(flag)
				f[i][j] = (i != 0 ? f[i-1][j] : 0) + (j != 0 ? f[i][j-1] : 0);
		}
	}
	printf("%lld", f[x][y]);
	return 0;
}
