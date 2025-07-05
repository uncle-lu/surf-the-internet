#include<cstdio>
#include<cmath>

int main() {
	int n, temp;
	scanf("%d", &n);
	for(int i = n; i >= 0; i--) {
		scanf("%d", &temp);
		if(temp == 0)continue;
		if(i != n || temp < 0)printf("%c", temp > 0 ? '+' : '-');
		if(abs(temp) > 1 || i == 0)printf("%d", abs(temp));
		if(i != 0)printf("x");
		if(i > 1)printf("^%d", i);
	}

	return 0;
}
