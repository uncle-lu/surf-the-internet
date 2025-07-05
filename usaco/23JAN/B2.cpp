#include<cstdio>
#include<cstring>

const int N = 30;
const int M = 20;
int s[N], t[N], c[N], m[M], a[M], b[M], p[M], line[110];
bool used[M];
int n, mm, ans = 0x7f7f7f7f;

void check() {
	memset(line, 0, sizeof(line));
	int temp = 0;
	for (int i = 1; i <= mm; ++i) {
		if(!used[i])continue;
		temp += m[i];
		for (int j = a[i]; j <= b[i]; ++j)
			line[j] += p[i];
	}

	for (int i = 1; i <= n; ++i)
		for (int j = s[i]; j <= t[i]; ++j) 
			if(line[j] < c[i])return ;

	if(temp < ans)
		ans = temp;
	return ;
}

void DFS(int x) {
	if(x > mm) {
		check();
		return ;
	}
	used[x] = true;
	DFS(x+1);
	used[x] = false;
	DFS(x+1);
	return ;
}

int main() {
	scanf("%d %d", &n, &mm);
	for (int i = 1; i <= n; ++i) 
		scanf("%d %d %d", &s[i], &t[i], &c[i]);
	for (int i = 1; i <= mm; ++i) {
		scanf("%d %d %d %d", &a[i], &b[i], &p[i], &m[i]);
	}
	DFS(1);
	printf("%d", ans);
	return 0;
}
