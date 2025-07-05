#include<cstdio>
#include<cmath>
int line[60];
int main() {
	int n, l, r, sum = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i]);
		sum += line[i];
	}
	scanf("%d %d", &l, &r);
	if(sum < l * n || sum > r * n) {
		printf("-1");
		return 0;
	}
	int in = 0, out = 0;
	for(int i=1; i<=n; i++) {
		if(line[i] < l)
			in += (l - line[i]);
		else if(line[i] > r)
			out += (line[i] - r);
	}
	printf("%d", in > out ? in : out);
	return 0;
}
