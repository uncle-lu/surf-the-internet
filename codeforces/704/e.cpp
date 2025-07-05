#include<cstdio>//uncle-lu
#include<algorithm>
#include<vector>
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') { f|=(ch=='-'); ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	x = f ? -x : x;
	return ;
}

int n, m;
std::vector<std::vector<int> >line;

void print()
{
	printf("Yes\n");
	for (int i = 0; i < m; i++) 
		printf("%d ", line[0][i]);
	exit(0);
}

bool check()
{
	for (int i = 1; i < n; i++) 
	{
		int cnt = 0;
		for (int j = 0; j < m && cnt <= 2; j++) 
		{
			if(line[0][j] != line[i][j])
				cnt++;
		}
		if(cnt > 2)
			return false;
	}

	return true;
}

void DFS(int sit, int x)
{
	if(x > 2)
		return ;

	for(int i=0; i<m; ++i)
	{
		if(line[0][i] != line[sit][i])
		{
			int temp = line[0][i];
			line[0][i] = line[sit][i];

			if(check())
				print();

			DFS(sit, x+1);

			line[0][i] = temp;
		}
	}

	return ;
}

int main()
{
	read(n);read(m);
	int temp;
	line.resize(n);
	for(int i=0; i<n; ++i)
	{
		for (int j = 0; j < m; j++) 
		{
			read(temp);
			line[i].push_back(temp);
		}
	}

	if(check())
	{
		print();
		return 0;
	}

	bool flag = false;
	int sit = 1;
	while(!flag && sit < n)
	{
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			if(line[sit][i] != line[0][i])
				cnt++;
		}
		if(cnt >= 5)
		{
			flag = true;
			break;
		}
		if(cnt == 3 || cnt == 4)
			break;
		sit++;
	}

	if(flag)
	{
		printf("No");
		return 0;
	}

	DFS(sit, 1);

	printf("No");

	return 0;
}
