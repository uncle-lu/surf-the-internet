#include<cstdio>

char maps[30][30];
char target[10] = "zhili";

int main() {
	int T, n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++){
			scanf("%s", maps[i]);
		}
		int flag = 0;
		for(int i=0; i<m; i++) {
			for(int j=1; j<=n; j++) {
				if(maps[j][i] == target[flag]){
					flag++;
					break;
				}
			}
			if(flag == 5)
				break;
		}
		if(flag == 5)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
