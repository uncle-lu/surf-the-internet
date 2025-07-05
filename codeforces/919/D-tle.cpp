#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5+10;
int n, q, cnt;
int type[N], num[N];
__int128 s[N];

int search(long long int x, int r) {
	int l=1, mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(s[mid] < x)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

void solve() {
	memset(type, 0, sizeof(type));
	memset(num, 0, sizeof(num));
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &type[i], &num[i]);
		if(type[i] == 1)
			s[i] = s[i-1] + 1;
		else {
			s[i] = s[i-1] * (1LL*num[i] + 1);
			num[i] = num[i-1];
		}
	}
	long long int temp;
	for(int i=1; i<=q; i++) {
		scanf("%lld", &temp);
		int l = search(temp, n);
		while(l > 0) {
			if(s[l] == temp) {
				printf("%d ", num[l]);
				break;
			}
			if(type[l] == 2) {
				if(temp % s[l-1] == 0){
					printf("%d ", num[l-1]);
					break;
				}
				temp = temp%s[l-1];
			}
			else
				l--;
			l = search(temp, l);
		}
	}
	printf("\n");
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}
