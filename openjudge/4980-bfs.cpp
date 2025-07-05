#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

struct node{
	int x, y, t;
	friend bool operator<(node a, node b)
	{
		return a.t > b.t;
	}
};
int n, m;
char map[210][210];
bool visit[210][210];
int x_turn[4]={1,-1,0,0};
int y_turn[4]={0,0,1,-1};
int start_x, start_y, end_x, end_y;

void BFS()
{
	std::priority_queue<node>qu;
	node now = (node){start_x, start_y, 0};
	visit[start_x][start_y] = true;
	qu.push(now);

	while(!qu.empty())
	{
		now = qu.top();
		qu.pop();

		if(now.x == end_x && now.y == end_y)
		{
			printf("%d\n", now.t);
			return ;
		}

		for(int i=0; i<4; ++i)
		{
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];

			if(xx >= n || xx < 0 || yy < 0 || yy >= m || visit[xx][yy] || map[xx][yy] == '#')
				continue;

			visit[xx][yy] = true;
			node new_now;
			new_now.x = xx; new_now.y = yy;
			new_now.t = now.t + (map[xx][yy] == 'x' ? 2 : 1);
			qu.push(new_now);
		}
	}
	printf("Impossible\n");
	return ;
}

int main()
{
	int s;
	scanf("%d", &s);
	while(s--)
	{
		scanf("%d %d\n", &n, &m);
		for(int i=0; i<n; ++i)
			scanf("%s", map[i]);

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
			{
				if(map[i][j]=='r') { start_x = i; start_y = j; }
				if(map[i][j]=='a') { end_x = i; end_y = j; }
			}

		memset(visit, 0, sizeof(visit));
		BFS();
	}

	return 0;
}
