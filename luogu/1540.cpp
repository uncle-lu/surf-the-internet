#include<cstdio>

int line[1010];

int main() {
	int m, n, temp, head = 0, last = -1, cnt = 0;
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &temp);
		bool flag = false;
		for(int j=head; j<=last; j++) 
			if(line[j] == temp){
				flag = true;
				break;
			}
		if(!flag) {
			line[++last] = temp;
			cnt++;
			while(last - head + 1 > m)
				head++;
		}
	}
	printf("%d", cnt);
	return 0;
}
