#include<cstdio>

char str[15];

int main() {
	int sum = 0;
	scanf("%s", str);
	for(int i=0, cnt=0; i < 12; i++) {
		if(str[i] == '-')continue;
		cnt++;
		sum += cnt * (str[i] - '0');
	}
	sum %= 11;
	if(sum == (str[12] == 'X' ? 10 : str[12] - '0'))
		printf("Right");
	else {
		str[12] = sum == 10 ? 'X' : '0' + sum;
		printf("%s", str);
	}
	return 0;
}
