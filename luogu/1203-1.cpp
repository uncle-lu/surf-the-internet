#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 710;
char str[N];
int lr[N], lb[N], rr[N], rb[N];

int main() {
	int n;
	scanf("%d\n%s", &n, str);
	for (int i = 0; i < n; ++i) 
		str[i+n] = str[i];
	n *= 2;
	if(str[0] == 'r')
		lr[0] = 1;
	else
		lb[0] = 1;
	for (int i = 1; i < n; ++i) {
		if(str[i] == 'w') {
			lr[i] = lr[i-1] + 1;
			lb[i] = lb[i-1] + 1;
		}
		else if(str[i] == 'b') 
			lb[i] = lb[i-1] + 1;
		else
			lr[i] = lr[i-1] + 1;
	}
	if(str[n-1] == 'r')
		rr[n-1] = 1;
	else
		rb[n-1] = 1;
	for (int i = n-2; i >= 0; --i) {
		if(str[i] == 'w') {
			rr[i] = rr[i+1] + 1;
			rb[i] = rb[i+1] + 1;
		}
		else if(str[i] == 'b')
			rb[i] = rb[i+1] + 1;
		else
			rr[i] = rr[i+1] + 1;
	}
	int ans = 0;
	for (int i = 0; i < n-1; ++i) {
		ans = max(ans, max(lr[i], lb[i]) + max(rr[i+1], rb[i+1]));
	}
	if(ans > n/2)
		ans = n/2;
	printf("%d", ans);
	return 0;
}
