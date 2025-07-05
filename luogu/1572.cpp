#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		long long int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

char str[110];

int main() {
	scanf("%s", str);
	int len = strlen(str), curr = 0, flag = 1;
	long long int a = 0, b = 1;
	if(str[0] == '-'){
		flag = -1;
		curr++;
	}
	while(curr < len) {
		long long int c = 0, d = 0;
		while(str[curr] >= '0' && str[curr] <= '9'){
			c = c * 10 + str[curr] - '0';
			curr++;
		}
		curr++;
		while(curr < len && str[curr] >= '0' && str[curr] <= '9'){
			d = d * 10 + str[curr] - '0';
			curr++;
		}
		c = c * b;
		a = a * d;
		b = b * d;
		a = a + flag * c;
		if(str[curr] == '-')
			flag = -1;
		else
			flag = 1;
		curr++;
		long long int temp = gcd(abs(a), b);
		a = a/temp; b = b/temp;
	}
	if(b == 1)
		printf("%lld", a);
	else 
		printf("%lld/%lld", a, b);
	return 0;
}
