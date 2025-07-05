#include<cstdio>
#include<cstring>
char str[1000010];
int main() {
	scanf("%s", str);
	int len = strlen(str), cnt=0;
	for(int i=0; i<len-1; i++) 
		if(str[i] != str[i+1])
			cnt++;
	if(str[len-1] != '1')
		cnt++;
	printf("%d", cnt);
	return 0;
}
