#include<cstdio>
#include<cstring>
char line[100010];
int main() {
	scanf("%s", line);
	int len = strlen(line), cnt=0, ans=0;
	for(int i=0; i<len; i++) {
		if(line[i] == '(')
			cnt++;
		else {
			if(cnt)
				cnt--;
			else {
				ans++;
				cnt++;
			}
		}
	}
	ans = ans + cnt/2;
	printf("%d", ans);
	return 0;
}
