#include<cstdio>//uncle-lu
#include<iostream>
#include<cstring>
#include<algorithm>

char line[200], ans[22][200], taget[22][200];
int n, m;

void check(int x, int y)
{
	for(int i=1; i<=n; ++i)
	{
		int len = strlen(taget[i]);
		if(len != y-x+1)continue;

		bool flag = true;
		for(int curr=0; curr<len && flag; ++curr)
			if(line[x+curr]!=taget[i][curr])
				flag = false;

		if(flag)
		{
			printf("%s ", ans[i]);
			return ;
		}
	}

	for(int curr = x; curr <= y; ++curr)
		printf("%c", line[curr]);
	printf(" ");
	return ;
}

int main()
{
	scanf("%d\n", &n);
	for(int i=1; i<=n; ++i)
	{
		std::cin.getline(line,200);
		int len = strlen(line);
		int point;
		for(point=0; point<len; ++point)
			if(line[point]==' ')
				break;

		line[point]='\0';
		strcpy(ans[i], line+point+1);
		strcpy(taget[i], line);
	}

	scanf("%d\n", &m);
	for(int i=1; i<=m; ++i)
	{
		std::cin.getline(line,200);
		int len = strlen(line);
		int pos1=0, pos2=0;
		for(pos2=0; pos2<=len; ++pos2)
			if(line[pos2]==' ')
			{
				check(pos1, pos2-1);
				pos1 = pos2+1;
			}
			else if(pos2 == len)
				check(pos1, pos2-1);
		printf("\n");
	}

	return 0;
}
