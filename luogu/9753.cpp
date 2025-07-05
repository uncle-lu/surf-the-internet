#include<cstdio>
#include<cstring>

const int N = 2e6+10;
int n;
char line[N];
long long int p[N], g[N][30], f[N];

int main() {
	scanf("%d", &n);
	scanf("%s", line+1);
	
	for(int i=n-1; i>=1; i--) {
		if(line[i+1] == line[i]) 
			p[i] = i+1;
		else {
			if(g[i+1][line[i]-'a'])
				p[i] = g[i+1][line[i]-'a'] + 1;
		}
		for(int c=0; c<26; c++) {
			if(line[p[i]+1]-'a' == c)
				g[i][c] = p[i];
			else
				g[i][c] = g[p[i]+1][c];
		}
	}

	for(int i=n; i>=1; i--) {
		if(p[i] != 0) f[i] = f[p[i]+1] + 1;
	}

	long long int ans = 0;
	for(int i=1; i<=n; i++)
		ans += f[i];

	printf("%lld",ans);

	return 0;
}
