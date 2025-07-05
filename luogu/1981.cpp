#include<cstdio>
const int N = 100010;
long long int sta[N];
int top;
int main() {
	char ch; bool flag = false;
	while(~scanf("%c", &ch)) {
		if(ch >= '0' && ch <= '9') {
			sta[top] = sta[top]*10 + ch - '0';
		}
		else {
			if(flag) {
				sta[top-1] *= sta[top];
				sta[top-1] %= 10000;
				sta[top] = 0;
				flag = false;
				top--;
			}
			top++;
			if(ch == '*') 
				flag = true;
		}
	}
	while(top > 0) {
		sta[top-1] = (sta[top-1] + sta[top]) % 10000;
		top--;
	}
	printf("%lld", sta[0]);
	return 0;
}
