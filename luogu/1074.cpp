#include<cstdio>//uncle-lu
#include<algorithm>

struct node{
	int x, y;
};
node search_list[100];
node zero_cnt[10];
int map[10][10], cnt, sum;
int ans = -1;
bool visit1[10][10];//行
bool visit2[10][10];//列
bool visit3[10][10];//小方格

bool cmp(node a, node b) { return a.x < b.x; }

int sit1(int x, int y) { return (x-1)/3*3 + (y-1)/3; }

int point(int x,int y)
{
    if(x==1||y==1||x==9||y==9)   return 6;
    if(x==2||y==2||x==8||y==8)   return 7;
    if(x==3||y==3||x==7||y==7)   return 8;
    if(x==4||y==4||x==6||y==6)   return 9;
    return 10;
}

void DFS(int curr)
{
	if(curr > cnt)
	{
		if(sum > ans)
			ans = sum;
		return ;
	}
	int x = search_list[curr].x, y = search_list[curr].y;
	for(int i=1; i<=9; ++i)
	{
		if(visit1[x][i]||visit2[y][i]||visit3[sit1(x, y)][i])continue;
		visit1[x][i] = visit2[y][i] = visit3[sit1(x, y)][i] = true;
		sum += point(x, y) * i;
		DFS(curr + 1);
		sum -= point(x, y) * i;
		visit1[x][i] = visit2[y][i] = visit3[sit1(x, y)][i] = false;
	}

	return ;
}

int main()
{
	for(int i=1; i<=9; ++i)
		for(int j=1; j<=9; ++j)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0)
			{
				visit1[i][map[i][j]] = true;
				visit2[j][map[i][j]] = true;
				visit3[sit1(i, j)][map[i][j]] = true;
				sum += point(i, j) * map[i][j];
			}
		}

	for(int i=1; i<=9; ++i)
	{
		for(int j=1; j<=9; ++j)
			if(map[i][j] == 0)
			{
				zero_cnt[i].x++;
			}
		zero_cnt[i].y = i;
	}

	std::sort(zero_cnt+1, zero_cnt+10, cmp);

	for(int i=1; i<=9; ++i)
	{
		int l = zero_cnt[i].y;
		for(int j=1; j<=9; ++j)
			if(map[l][j] == 0)
				search_list[++cnt] = (node){l, j};
	}

	DFS(1);
	printf("%d", ans);
	return 0;
}
