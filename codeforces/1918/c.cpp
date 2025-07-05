#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		long long int a, b, r, x = 0, temp;
		scanf("%lld %lld %lld", &a, &b, &r);
		if(a < b)swap(a, b);
		temp = 1LL << 62;
		while((temp & a) == (temp & b) && temp > 0)temp >>= 1;
		temp >>= 1;
		while(temp > 0) {
			if((temp & a) != 0 && (temp & b) == 0 && x + temp <= r)
				x += temp;
			temp >>= 1;
		}
		printf("%lld\n", abs((a^x) - (b^x)));
	}
	return 0;
}
