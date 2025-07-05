#include<cstdio>
#include<cstring>
char line[110];
int main() {
	scanf("%s", line);
	int len = strlen(line);
	int A=0, B=0, C=0, D=0, temp=0, flag = 1;
	char c;
	for(int i=0; i<len; i++) {
		if(line[i] <= '9' && line[i] >= '0') {
			temp = temp * 10 + line[i]-'0';
			continue;
		}
		if(line[i] <= 'z' && line[i] >= 'a') {
			if(temp == 0) temp = 1;
			c = line[i];
			A += flag * temp;
			flag = 1; temp = 0;
			continue;
		}
		B += flag * temp;
		flag = 1; temp = 0;
		if(line[i] == '=') {
			C = A; D = B;
			A = 0; B = 0;
		}
		else if(line[i] == '-') {
			flag = -1;
		}
	}
	if(temp != 0) {
		B += flag*temp;
	}
	if(D-B == 0)
		printf("%c=0.000", c);
	else
		printf("%c=%.3lf", c, 1.0*(D-B)/(A-C));
	return 0;
}
