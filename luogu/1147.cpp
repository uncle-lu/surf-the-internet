#include<cstdio>
const int N = 2e6+10;
long long int line[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		line[i] = line[i-1] + i;
	}
	int last = 1;
	for(int i=1; i<n; i++) {
		while(line[i] - line[last] > n)last++;
		if(line[i] - line[last] == n)
			printf("%d %d\n", last+1, i);
	}
	return 0;
}
