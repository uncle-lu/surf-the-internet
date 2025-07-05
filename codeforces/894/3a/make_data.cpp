#include<cstdio>
#include<cstdlib>
#include<ctime>

int main() {
	srand(time(0));
	int T = 10;
	printf("%d\n", T);
	for(int t=1; t<=T; t++) {
		int n=20, m=10;
		printf("%d %d\n", n, m);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
				printf("%c", rand()%26 + 'a');
			printf("\n");
		}
	}
	return 0;
}
