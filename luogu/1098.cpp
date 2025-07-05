#include<cstdio>
#include<cstring>

char str[110];

bool isnumber(char x) {
	return x >= '0' && x <= '9';
}

bool isaph(char x) {
	return x >= 'a' && x <= 'z';
}

char p(char x, int p1) {
	if(p1 == 2 && isaph(x))
		return x - 'a' + 'A';
	if(p1 == 3)
		return '*';
	return x;
}

int main() {
	int p1, p2, p3, len;
	scanf("%d %d %d", &p1, &p2, &p3);
	scanf("%s", str);
	len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] == '-') {
			if(i == 0 || i == len-1){
				printf("-");
				continue;
			}
			else if((isnumber(str[i-1]) && isnumber(str[i+1])) || (isaph(str[i-1]) && isaph(str[i+1]))) {
				if(str[i-1] == str[i+1] - 1)
					continue;
				if(str[i-1] < str[i+1]) {
					if(p3 == 1) {
						for(char j = str[i-1]+1; j < str[i+1]; j++)
							for(int t = 1; t <= p2; t++)
								printf("%c", p(j, p1));
					}
					else {
						for(char j = str[i+1]-1; j >= str[i-1]+1; j--)
							for(int t = 1; t <= p2; t++)
								printf("%c", p(j, p1));
					}
					continue;
				}
			}
		}
		printf("%c", str[i]);
	}
	return 0;
}
