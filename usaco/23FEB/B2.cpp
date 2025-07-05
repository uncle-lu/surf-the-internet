#include<cstdio>
#include<cstring>

const int N = 30;
char paint[N][N], str[N][N], target[N][N], temp[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		memset(paint, 0, sizeof(paint));
		memset(str, 0, sizeof(str));
		memset(target, '.', sizeof(target));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("\n%s", paint[i]);
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) 
			scanf("\n%s", str[i]);

		for (int i = 0; i <= n-k; ++i) {
			for (int j = 0; j <= n-k; ++j) {
				for (int t = 0; t < 4; ++t) {
					bool flag = true;
					for (int a = 0; a < k && flag; ++a)
						for (int b = 0; b < k && flag; ++b)
							if(paint[i+a][j+b] == '.' && str[a][b] != '.')
								flag = false;

					if(flag){
						for (int a = 0; a < k; ++a) 
							for (int b = 0; b < k; ++b) 
								if(target[i+a][j+b] == '.' && str[a][b] != '.')
									target[i+a][j+b] = '*';
					}

					memcpy(temp, str, sizeof(str));
					for (int a = 0; a < k; ++a)
						for (int b = 0; b < k; ++b) 
							str[a][b] = temp[k-1-b][a];
				}
			}
		}

		bool flag = true;
		for (int i = 0; i < n && flag; ++i) 
			for (int j = 0; j < n && flag; ++j) 
				if(target[i][j] != paint[i][j])
					flag = false;

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
