#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int N = 52;
int tong[N], in[N];
bool vis[N], this_vis[N];

int trans(char x)
{
	if(x >= 'a' && x <= 'z')
		return x - 'a';
	return x - 'A' + 26;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string a, b;
		cin >> a >> b;

		int len = a.length(), used = 0, cnt = 0;
		bool flag = false;
		memset(tong, -1, sizeof(tong));
		memset(in, 0, sizeof(in));
		memset(vis, false, sizeof(vis));

		for (int i = 0; i < len; ++i) {
			int ai = trans(a[i]), bi = trans(b[i]);
			if(tong[ai] != bi && tong[ai] != -1) {
				flag = true;
				break;
			}
			if(~tong[ai])continue;
			tong[ai] = bi;
			in[bi]++;
			used++;
		}

		if(flag) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < N; ++i) 
		{
			if(tong[i] == i) 
				tong[i] = -1;
			if(in[i] == 0)
				used--;
		}
		for (int i = 0; i < N; ++i) {
			if(tong[i] == -1)continue;
			cnt++;
			if(vis[i])continue;
			memset(this_vis, false, sizeof(this_vis));
			vis[i] = this_vis[i] = true;
			int temp = i, curr;
			bool yescircle = false;
			while(tong[temp] != -1 && !vis[tong[temp]]) {
				temp = tong[temp];
				vis[temp] = true;
				this_vis[temp] = true;
			}
			if(tong[temp] != -1 && this_vis[tong[temp]]) {
				curr = temp;
				do {
					if(in[curr]>=2) {
						yescircle = true;
						break;
					}
					curr = tong[curr];
				} while(curr != temp);
				if(used < 52 && !yescircle){
					cnt++;
					yescircle = true;
				}
				if(!yescircle) {
					flag = true;
					break;
				}
			}
		}
		if(flag) {
			cout << -1 << endl;
		}
		else {
			cout << cnt << endl;
		}
	}

	return 0;
}
