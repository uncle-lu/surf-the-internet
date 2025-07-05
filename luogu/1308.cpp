#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6+10;
char str[15];
char line[N];

int main() {
	cin.getline(str, sizeof(str));
	cin.getline(line, sizeof(line));
	int cnt = 0, sit = -1, slen = strlen(str), len = strlen(line);
	for(int i=0; i<slen; i++)
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	for(int i=0; i<len; i++)
		if(line[i] >= 'A' && line[i] <= 'Z')
			line[i] = line[i] - 'A' + 'a';
	for(int i=0; i<len; i++) {
		if((i == 0 || line[i-1] == ' ') && line[i] == str[0]) {
			bool flag = true;
			for(int j=0; j<slen; j++) 
				if(line[i+j] != str[j]){
					flag = false;
					break;
				}
			if(!flag)continue;
			if(flag && !(line[i+slen] >= 'a' && line[i+slen] <= 'z')){
				cnt++;
				if(sit == -1)
					sit = i;
			}
		}
	}
	if(cnt == 0) 
		printf("-1");
	else
		printf("%d %d", cnt, sit);
	return 0;
}
