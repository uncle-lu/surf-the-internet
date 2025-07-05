#include<cstdio>
#include<cmath>
using namespace std;

int line[10][5], temp[5], n;

bool checkone(int x) {
	int cnt = 0, dif[6]={-1};
	for(int i = 0; i < 5; i++) 
		if(line[x][i] != temp[i])
			dif[cnt++] = i;
	if(cnt > 2)
		return false;
	if(cnt == 1)
		return true;
	if(abs(dif[0] - dif[1]) != 1)
		return false;
	for(int i = 1; i <= 9; i++)  // 枚举两个同时转的幅度(大小)
		if((line[x][dif[0]] + i) % 10 == temp[dif[0]] && (line[x][dif[1]] + i) % 10 == temp[dif[1]])
			return true;
	return false;
}

bool check() {
	for(int i = 1; i <= n; i++) 
		if(!checkone(i))
			return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j < 5; j++)
			scanf("%d", &line[i][j]);

	int ans = 0;
	for(temp[0] = 0; temp[0] <= 9; temp[0]++)
		for(temp[1] = 0; temp[1] <= 9; temp[1]++)
			for(temp[2] = 0; temp[2] <= 9; temp[2]++)
				for(temp[3] = 0; temp[3] <= 9; temp[3]++)
					for(temp[4] = 0; temp[4] <= 9; temp[4]++)
						if(check()) {
							ans++;
						}

	printf("%d", ans);
	return 0;
}
