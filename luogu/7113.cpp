#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

__int128 gcd(__int128 x, __int128 y){
	while(y){
		__int128 t = x%y;
		x = y;
		y = t;
	}
	return x;
}

void print(__int128 x) {
	if(x > 9)print(x/10);
	printf("%d", (int)(x%10));
	return ;
}

struct fac{
	__int128 x, y;
	friend fac operator+(const fac a, const fac b) {
		fac temp;
		if(a.x == 0)
			return b;
		if(b.x == 0)
			return a;
		temp.x = b.y * a.x + a.y * b.x;
		temp.y = a.y * b.y;
		__int128 t = gcd(temp.x, temp.y);
		temp.x /= t;
		temp.y /= t;
		return temp;
	}
	friend fac operator/(const fac a, const int b) {
		fac temp;
		temp.y = a.y * b;
		temp.x = a.x;
		__int128 t=gcd(temp.x, temp.y);
		temp.x /= t;
		temp.y /= t;
		return temp;
	}
};
const int N = 1e5+10;
int n, m;
int out[N], in[N];
fac line[N];
vector<int>edge[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		int temp;
		scanf("%d", &out[i]);
		for(int j=1; j<=out[i]; j++){
			scanf("%d", &temp);
			in[temp]++;
			edge[i].push_back(temp);
		}
	}
	queue<int>qu;
	for(int i=1; i<=m; i++)
	{
		line[i].x=1; line[i].y=1;
		qu.push(i);
	}

	while(!qu.empty()) {
		int now = qu.front(); qu.pop();
		
		for(auto i: edge[now]) {
			line[i] = line[i] + (line[now]/out[now]);
			in[i]--;
			if(!in[i]){
				qu.push(i);
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(out[i] == 0)
		{
			print(line[i].x);
			printf(" ");
			print(line[i].y);
			printf("\n");
		}

	return 0;
}
