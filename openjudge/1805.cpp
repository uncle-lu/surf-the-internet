#include<cstdio>
#include<cstring>
#include<algorithm>

int target, num, sit;
int t[10], ans, ans_line[10], ans_cnt, line[10];
bool flag;

void DFS(int x, int last, int cnt)
{
	if(x > sit)
	{
		if(last <= target && ans < last)
		{
			flag = false;
			memcpy(ans_line, line, sizeof(line));
			ans = last;
			ans_cnt = cnt;
		}
		else if(ans == last)
			flag = true;

		return ;
	}

	int temp = 0;
	for(int i=x; i<=sit; i++)
	{
		temp = temp*10 + t[i];
		if(temp + last <= target)
		{
			line[cnt+1] = temp;
			DFS(i+1, temp+last, cnt+1);
			line[cnt+1] = 0;
		}
		else
			break;
	}

	return ;
}

void init()
{
	ans = 0; ans_cnt = 0; flag = false;
	memset(t, 0, sizeof(t));
	memset(ans_line, 0, sizeof(ans_line));
	memset(line, 0, sizeof(line));
	return ;
}

int main()
{
	while(true)
	{
		init();
		scanf("%d %d", &target, &num);
		if(target == 0 && num == 0)
			break;
		if(target == num)
		{
			printf("%d %d\n", target, num);
			continue;
		}
		sit=0;
		do {
			sit++;
			t[sit] = num%10;
			num/=10;
		} while(num);
		for(int i=1; i<=sit/2; i++)
			std::swap(t[i], t[sit-i+1]);
		
		DFS(1, 0, 0);

		if(flag)
		{
			printf("rejected\n");
		}
		else if(ans_cnt == 0)
		{
			printf("error\n");
		}
		else
		{
			printf("%d ", ans);
			for(int i=1; i<=ans_cnt; ++i)
				printf("%d ", ans_line[i]);
			printf("\n");
		}
	}

	return 0;
}
