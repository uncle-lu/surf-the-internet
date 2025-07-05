#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010;
const int Mod = 998244353;
int maps[N][N];
int f[N][N];

int main() {
	int T, id;
	scanf("%d %d", &T, &id);
	while(T--) {
		memset(maps, 0, sizeof(maps));
		memset(f, 0, sizeof(f));
		int n, m, c, ff;
		char temp;
		scanf("%d %d %d %d", &n, &m, &c, &ff);
		for(int i=1; i<=n; i++) {
			scanf("\n");
			for(int j=1; j<=m; j++) {
				scanf("%c", &temp);
				maps[i][j] = (temp == '0' ? 0:1);
			}
		}
		for(int i=1; i<=n; i++) 
			for(int j=m; j>=1; j--) {
				if(maps[i][j])f[i][j] = -1;
				else if(j != m)f[i][j] = f[i][j+1] + 1;
			}
		long long int ansc = 0, ansf = 0;
		for(int j=1; j<m; j++) {
			long long int cntc = 0, cntf = 0;
			for(int i=1; i<=n; i++) {
				if(f[i][j] == -1) {
					cntc = 0; cntf = 0;
					continue;
				}
				ansf = (ansf + cntf) % Mod;
				cntf += f[i][j] * cntc;
				ansc = (ansc +  f[i][j] * cntc % Mod) % Mod;
				cntc += max(0, f[i-1][j]);
			}
		}

		printf("%lld %lld\n", ansc*c%Mod, ansf*ff%Mod);
	}

	return 0;
}
