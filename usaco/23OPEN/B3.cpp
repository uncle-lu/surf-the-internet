#include<cstdio>

const int N = 1e5 * 2 + 10;

int A[N], line[N];

int main() {
	int n, k, t;
	scanf("%d %d %d", &n, &k, &t);
	for (int i = 0; i < k; ++i) 
		scanf("%d", &A[i]);
	A[k] = n;

	int mode = 0;
	for (int i = 0; i < n; ++i) {
		if(i >= A[mode+1])
			mode++;

		int temp = t - (i - A[mode] + 1), end;
		if(temp >= 0) {
			temp = 1 + temp / (A[mode+1] - A[mode]);
			end = (i + temp * (A[mode+1] - A[mode])) % n;
		}
		else
			end = i;
		line[end] = i;
	}

	for (int i = 0; i < n; ++i) 
		printf("%d ", line[i]);

	return 0;
}
