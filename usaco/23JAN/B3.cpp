#include<cstdio>
#include<cstring>

int main() {
	int n;
	char line[110];
	scanf("%d\n", &n);
	for (int t = 1; t <= n; ++t) {
		scanf("%s", line);
		int len = strlen(line), ans = 0;
		if(len < 3 || (len == 3 && line[1] != 'O')){
			printf("-1\n");
			continue;
		}
		if(len == 3) {
			if(line[0] != 'M') ans++;
			if(line[2] != 'O') ans++;
			printf("%d\n", ans);
			continue;
		}
		ans = 4;
		for (int i = 1; i < len-1; ++i) {
			if(line[i] == 'O'){
				int temp = 0;
				if(line[i-1] != 'M') temp++;
				if(line[i+1] != 'O') temp++;
				if(temp < ans)
					ans = temp;
			}
		}
		if(ans == 4)
			printf("-1\n");
		else
			printf("%d\n", ans + (len - 3));
	}
	return 0;
}
