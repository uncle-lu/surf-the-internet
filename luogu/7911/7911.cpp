#include<cstdio>
#include<cstring>

char type[10], line[30];
char server[1010][30];
int number[1010], cnt = 0;

bool check(int len) {
	int tempCnt = 0, flag = 0, temp = 0;
	for(int i=0; i<len; i++) {
		if(line[i] == '.')
			tempCnt++;
		else if(line[i] == ':'){
			if(flag == 1 || tempCnt != 3)
				return false;
			flag = 1;
		}
		else if(!(line[i] >= '0' && line[i] <= '9'))
			return false;
	}
	if(tempCnt != 3 || !flag)
		return false;
	tempCnt = 0;
	for(int i=0; i<len; i++) {
		if(line[i] >= '0' && line[i] <= '9'){
			temp = temp * 10 + line[i] - '0';
			if(temp > 65535)return false;
		}
		else {
			if(i == 0 || i == len-1)
				return false;
			if(!(line[i-1] >= '0' && line[i-1] <= '9'))
				return false;
			if(!(line[i+1] >= '0' && line[i+1] <= '9'))
				return false;
			if(tempCnt < 4 && temp > 255)
				return false;
			tempCnt++;
			temp = 0;
		}
	}
	if(line[0] == '0' && line[1]>='0' && line[1] <= '9')
		return false;
	for(int i=1; i<len; i++) 
		if(line[i] == '0' && !(line[i-1] >= '0' && line[i-1] <= '9') && (line[i+1]>='0' && (line[i+1] <= '9')))
			return false;
	return true;
}

int search() {
	for(int i=0; i<cnt; i++) 
		if(strcmp(line, server[i]) == 0) 
			return number[i];
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		scanf("%s %s", type, line);
		int len = strlen(line);
		if(!check(len)) {
			printf("ERR\n");
			continue;
		}
		if(type[0] == 'S') {
			if(search() != -1) 
				printf("FAIL\n");
			else {
				printf("OK\n");
				strcpy(server[cnt], line);
				number[cnt] = i;
				cnt++;
			}
		}
		else {
			int temp = search();
			if(temp == -1) 
				printf("FAIL\n");
			else 
				printf("%d\n", temp);
		}
	}
	return 0;
}
