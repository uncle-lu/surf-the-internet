#include<cstdio>

const int N = 2*(5e5+10);
int line[N], line1[N], line2[N], n, len1, len2;
char ans[N];

bool check() {
	int f1=1, e1=len1-1, f2=1, e2=len2-1;
	for(int i=1; i<=n/2; i++) {
		if(f1 <= e1) {
			if(line1[f1] == line1[e1] && f1 != e1) {
				ans[i] = 'L'; ans[n-i+1] = 'L'; f1++; e1--;
				continue;
			}
			if(line1[f1] == line2[e2]) {
				ans[i] = 'L'; ans[n-i+1] = 'R'; f1++; e2--;
				continue;
			}
		}
		if(f2 <= e2) {
			if(line2[f2] == line1[e1]) {
				ans[i] = 'R'; ans[n-i+1] = 'L'; f2++; e1--;
				continue;
			}
			if(line2[f2] == line2[e2] && f2 != e2) {
				ans[i] = 'R'; ans[n-i+1] = 'R'; f2++; e2--;
				continue;
			}
		}
		return false;
	}
	return true;
}

bool check1() {
	line1[1] = line[1];
	for(len1=2; line[len1-1] != line[1] || len1==2; len1++)
		line1[len1] = line[len1];
	for(len2=1; line[n-len2+1] != line[1]; len2++)
		line2[len2] = line[n-len2+1];
	
	if(!check())return false;

	for(int i=1; i<=n; i++)
		printf("%c", ans[i]);
	printf("\n");
	return true;
}

bool check2() {
	line2[1] = line[n];
	for(len2=2; line[n-len2+2] != line[n] || len2==2; len2++)
		line2[len2] = line[n-len2+1];
	for(len1=1; line[len1] != line[n]; len1++)
		line1[len1] = line[len1];

	if(!check())return false;

	ans[n] = 'L';
	for(int i=1; i<=n; i++)
		printf("%c", ans[i]);
	printf("\n");
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		n*=2;
		for(int i=1; i<=n; i++) 
			scanf("%d", &line[i]);

		if((!check1()) && (!check2()))
			printf("-1\n");
	}
	return 0;
}
