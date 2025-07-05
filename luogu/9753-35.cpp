#include<cstdio>
#include<cstring>

const int N = 2e6+10;
char str[N];
int n, sta[N], top;

int main() {
	scanf("%d", &n);
	scanf("%s", str);

	int ans = 0;
	for(int i = 0; i < n; i++) {
		top = 0;
		for(int j = i; j < n; j++){
			if(sta[top] == str[j])
				top--;
			else {
				top++;
				sta[top] = str[j];
			}
			if(top == 0)
				ans++;
		}
	}

	printf("%d", ans);
	return 0;
}
