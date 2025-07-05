#include<cstdio>

const int N = 1e4*3+10;
int line[N], pre[N], back[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	for(int i=1; i<=n; i++)
		if(line[i] == 2)
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[i-1];
	for(int i=n; i>=1; i--)
		if(line[i] == 1)
			back[i] = back[i+1] + 1;
		else
			back[i] = back[i+1];
	int ans = pre[0] + back[1];
	for(int i=1; i<=n; i++)
		if(ans > pre[i] + back[i+1])
			ans = pre[i] + back[i+1];
	printf("%d", ans);
	return 0;
}
