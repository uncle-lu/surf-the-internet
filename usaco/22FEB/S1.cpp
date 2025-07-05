#include<iostream>
#include<vector>
using namespace std;

const int N = 510;

int maps[N][N];
int tong[N];
bool F[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		tong[i] = i;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			cin >> maps[i][j];

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) {
			F[i][maps[i][j]] = true;
			if(maps[i][j] == i)break;
		}

	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j) 
				if(F[i][k] && F[k][j])
					F[i][j] = true;

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j)
			if(F[maps[i][j]][i])
			{
				tong[i] = maps[i][j];
				break;
			}

	for (int i = 1; i <= n; ++i) 
		cout << tong[i] << '\n';
	
	return 0;
}
