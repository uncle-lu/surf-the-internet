#include<cstdio>
#include<cstring>

const int N = 3*1e5+10;
char line[N];
int F[N], sit[10];

int main() {
	scanf("%s", line+1);
	int len = strlen(line+1);
	for(int i = 1; i <= len; i++) {
		if(line[i] == 'b')
			sit[1] = i;
		else if(line[i] == 'i')
			sit[5] = sit[4];
		else if(line[i] == 's') {
			sit[4] = sit[3];
			sit[3] = sit[2];
		}
		else if(line[i] == 'e') {
			sit[2] = sit[1];
			sit[6] = sit[5];
		}
		F[i] = F[sit[6] - 1] + sit[6];
	}
	long long int ans = 0;
	for (int i = 1; i <= len; ++i) {
		ans += F[i];
	}
	printf("%lld", ans);
	return 0;
}
