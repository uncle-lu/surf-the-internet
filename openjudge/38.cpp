#include<cstdio>//uncle-lu
#include<cmath>
#include<algorithm>

int arr[30][30];

int main()
{
	int n, m, k, cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j] != 0)
				cnt ++;
		}

	int curr_x=0, curr_y=0, ans = 0;
	for(int i=1; i<=cnt; ++i)
	{
		int mx = -1;
		int target_x, target_y;
		for(int x=1; x<=n; x++)
			for(int y=1; y<=m; y++)
				if(mx < arr[x][y])
				{
					mx = arr[x][y];
					target_x = x; target_y = y;
				}

		if(curr_x == 0 && curr_y == 0)
			curr_y = target_y;

		int time_1 = abs(curr_x - target_x) + abs(curr_y - target_y);//走过去的时间
		int time_2 = target_x;//下一个点回家的时间

		if(time_1 > k)
		{
			break;
		}
		else if(time_1 + 1 + time_2 > k)
		{
			break;
		}

		curr_x = target_x;
		curr_y = target_y;

		ans += arr[target_x][target_y];
		arr[target_x][target_y] = 0;
		k -= time_1 + 1;
	}

	printf("%d", ans);
	return 0;
}
