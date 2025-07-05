#include<cstdio>
#include<cstdlib>
#include<ctime>

int main() {
	srand(time(0));
	int T = 10;
	printf("%d\n", T);
	while(T--) {
		bool flag = rand()%2;
		int n = rand()%10000+1;
		printf("%d\n", n);
		if(flag){
			for(int i=1; i<=n; i++) {
				printf("%d ", rand() % 50);
			}
		}
		else{
			for(int i=1; i<=n; i++)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
