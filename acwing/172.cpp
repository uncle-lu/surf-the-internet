#include<cstdio>
#include<cstring>

const int N = 110;
int n, m;
int line[N];

bool check(int x, int val) {
	for (int i = 1; i <= x; ++i)
		if(line[i] == val)return true;
	return false;
}

bool DFS(int x) {
	if(x == m) return line[m] == n;

	bool vis[N];
	memset(vis, false, sizeof(vis));
	for (int i = x; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			if(line[i] + line[j] > n || line[i] + line[j] < line[x])continue;
			if(vis[line[i] + line[j]] || check(x, line[i] + line[j]))continue;
			vis[line[i] + line[j]] = true;
			line[x+1] = line[i] + line[j];
			if(DFS(x+1)) return true;
		}
	}
	return false;
}

int main() {
	while(scanf("%d", &n) && n) {
		memset(line, 0, sizeof(line));
		m = 1; line[1] = 1;
		while(!DFS(1))
			m++;
		for (int i = 1; i <= m; ++i)
			printf("%d%c", line[i], i == m ? '\n' : ' ');
	}
	return 0;
}
