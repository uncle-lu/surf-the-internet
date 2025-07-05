#include <cstdio>
#include <vector>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m,fa[N][21],dep[N];
long long ans,f[N];
vector <int> edge[N];
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<(int)edge[x].size();i++){
		if(edge[x][i]==fa[x][0])continue;
		fa[edge[x][i]][0]=x;
		dfs(edge[x][i]);
	}
}

int Lca(int x,int y){
	if(dep[x] < dep[y])swap(x, y);
	for(int i=20; i>=0; i--) 
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]==fa[y][i])continue;
		x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
void dfs2(int x){
	for(int i=0;i<(int)edge[x].size();i++){
		if(edge[x][i]==fa[x][0])continue;
		dfs2(edge[x][i]);
		f[x]+=f[edge[x][i]];
	}
}
int main(){
	freopen("in","r",stdin);
	scanf("%d%d", &n, &m);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=0;i<=20;i++)fa[1][i]=1;
	dfs(1);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d", &x, &y);
		f[x]++;
		f[y]++;
		f[Lca(x,y)]-=2;
	}
	dfs2(1);
	for(int i=2;i<=n;i++){
		if(f[i]==0)ans+=m;
		if(f[i]==1)ans++;
	}
	printf("%lld", ans);
	return 0;
}
