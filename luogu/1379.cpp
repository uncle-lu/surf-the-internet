#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<cmath>
using namespace std;

struct node{
	int maps[3][3];
	int d, h;
	friend bool operator<(const node a, const node b) {
		return a.d + a.h > b.d + b.h;
	}
};
int _end[3][3] = { { 1, 2, 3, }, { 8, 0, 4, }, { 7, 6, 5, } };
unordered_map<int, int>vis;
int x_turn[4]={1, -1, 0, 0};
int y_turn[4]={0, 0, 1, -1};

int simplehash(int m[3][3]) {
	int temp = 0;
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j) 
			temp = temp * 9 + m[i][j];
	return temp;
}

int h(int m[3][3]) {
	int temp = 0;
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j) 
			for (int ei = 0; ei < 3; ++ei) 
				for (int ej = 0; ej < 3; ++ej) 
					if(m[i][j] == _end[ei][ej]) 
						temp += abs(i - ei) + abs(j - ej);
	return temp;
}

int main() {
	int start[3][3];
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j) 
			scanf("%1d", &start[i][j]);
	int end_h = simplehash(_end);
	node now;
	memcpy(now.maps, start, sizeof(now.maps));
	now.d = 0 ;
	now.h = h(start);
	priority_queue<node>qu;
	qu.push(now);
	while(!qu.empty()) {
		now = qu.top(); qu.pop();

		if(simplehash(now.maps) == end_h) {
			cout << now.d << endl;
			return 0;
		}

		if(vis.count(simplehash(now.maps)))continue;
		vis[simplehash(now.maps)] = 1;

		int x, y;
		for (int i = 0; i < 3; ++i) 
			for (int j = 0; j < 3; ++j) 
				if(now.maps[i][j] == 0) {
					x = i; y = j;
				}

		for (int i = 0; i < 4; ++i) {
			int xx = x + x_turn[i], yy = y + y_turn[i];
			if(xx < 0 || xx > 2 || yy < 0 || yy > 2)continue;
			node temp;
			memcpy(temp.maps, now.maps, sizeof(now.maps));
			swap(temp.maps[xx][yy], temp.maps[x][y]);
			temp.d = now.d + 1; temp.h = h(temp.maps);
			qu.push(temp);
		}
	}
	return 0;
}
