#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int>d(m), b[m];
		vector<bool>del(m);
		string temp;
		for (int i = 0; i < m; ++i) {
			cin >> temp >> d[i];
			for (int j = 0; j < n; ++j) {
				b[i].push_back(temp[j] - '0');
			}
			del[i] = false;
		}
		int cnt = m;
		while(cnt != 0)
		{
			bool flag = false;
			for (int i = 0; i < n; ++i) { // 枚举每一位
				bool vis[2][2]={ {0, 0}, {0, 0} };
				for (int j = 0; j < m; ++j) { // 枚举每个询问
					if(del[j])continue;
					vis[b[j][i]][d[j]] = true;
				}
				
				if(vis[0][0] xor vis[0][1] )
				{
					for (int j = 0; j < m; ++j)
						if(b[j][i] == 0 && !del[j])
						{
							del[j] = true; cnt--; flag = true;
						}
				}

				if(vis[1][1] xor vis[1][0])
				{
					for (int j = 0; j < m; ++j)
						if(b[j][i] == 1 && !del[j])
						{
							del[j] = true; cnt--; flag = true;
						}
				}
			}
			
			if(!flag && cnt != 0)
			{
				cout << "LIE" << '\n';
				break;
			}
		}
		
		if(cnt == 0)
			cout << "OK" << '\n';
	}

	return 0;
}
