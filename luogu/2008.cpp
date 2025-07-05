#include<cstdio>
#include<cstring>

int sum[20], tong[20], sit[20];

int main() {
	memset(tong, -1, sizeof(tong));
	int n, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);
		int mlen = 0, msit, target;
		for (int j = 0; j <= temp; ++j) {
			if(tong[j] == -1)continue;
			if(tong[j] + 1 > mlen || (tong[j] + 1 == mlen && msit > sit[j])){
				mlen = tong[j] + 1;
				target = j;
				msit = sit[j];
			}
		}
		if(mlen) {
			tong[temp] = tong[target] + 1;
			sum[temp] = sum[target] + temp;
		}
		else {
			tong[temp] = 1;
			sum[temp] = temp;
		}
		sit[temp] = i;
		printf("%d ", sum[temp]);
	}
	return 0;
}
