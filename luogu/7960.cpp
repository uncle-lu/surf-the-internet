#include<cstdio>

const int N = 1e7+10;
int vis[N], line[N], cnt;

bool check(int x) {
	if(x%7 == 0)return false;
	while(x) {
		if(x%10 == 7)return false;
		x /= 10;
	}
	return true;
}

void init() {
	for(int i=1; i<=N-1; i++){
		if(vis[i]==0) {
			if(check(i)) {
				vis[i] = ++cnt;
				line[cnt] = i;
			}
			else {
				for(int j=1; i*j <= N-1; j++)
					vis[i*j] = -1;
			}
		}
	}
}

int main() {
	init();
	int T, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &x);
		if(vis[x] == -1)
			printf("-1\n");
		else
			printf("%d\n", line[vis[x] + 1]);
	}
	return 0;
}
