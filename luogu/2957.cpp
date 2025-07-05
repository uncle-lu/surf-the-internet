#include<cstdio>
#include<cstring>

int main() {
	char line1[90], line2[90];
	scanf("%s\n%s", line1, line2);
	int len1 = strlen(line1), len2 = strlen(line2), ans = 0;
	for(int i=0; i<len1; i++) {
		if(line2[0] == line1[i]) {
			bool flag = true;
			for(int j=0; i+j<len1; j++) 
				if(line1[i+j] != line2[j]) {
					flag = false;
					break;
				}
			if(flag) {
				ans = len1 - i;
				break;
			}
		}
	}
	for(int i=0; i<len2; i++) {
		if(line1[0] == line2[i]) {
			bool flag = true;
			for(int j=0; i+j<len2; j++) 
				if(line2[i+j] != line1[j]) {
					flag = false;
					break;
				}
			if(flag) {
				if(ans < len2 - i)
					ans = len2 - i;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
