#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2505;
int n,m,k,a[N],f[N][N],ans;
vector <int> edge[N];
bool vis[N];
struct node{
	int num,v;
	friend bool operator <(const node A,const node B){
		return A.v>B.v;
	}
};
node d[N][N];
void bfs(int x){
	memset(vis,0,sizeof(vis));
	queue <node> q;
	q.push((node){x,0});
	vis[x]=1;
	while(!q.empty()){
		node now=q.front();
		if(now.v>k+1) return ;
		f[x][now.num]=now.v;
		q.pop();
		for(int i=0;i<(int)edge[now.num].size();i++){
			int to=edge[now.num][i];
			if(vis[to])continue;
			vis[to] = true;
			q.push((node){to,now.v+1});
		}
	}
}
int main(){
	memset(f,0x7f,sizeof(f));
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	for(int i=2;i<=n;i++){
		if(f[i][1]>k+1)continue;
		for(int j=2;j<=n;j++){
			if(i==j)continue;
			if(f[i][j]>k+1)continue;
			d[j][i]=(node){i,a[i]+a[j]};
		}
	}
	for(int i=2;i<=n;i++)sort(d[i]+1,d[i]+n+1);
	for(int b=2;b<=n;b++){
		for(int c=2;c<=n;c++){
			if(b==c)continue;
			if(f[b][c]>k+1)continue;
			for(int tb=1;tb<=3;tb++)
				for(int tc=1;tc<=3;tc++)
					if(d[b][tb].num!=c&&d[c][tc].num!=b&&d[b][tb].num!=d[c][tc].num)
						ans=max(ans,d[c][tc].v+d[b][tb].v);
		}
	}
	cout<<ans<<endl;
	return 0;
}
