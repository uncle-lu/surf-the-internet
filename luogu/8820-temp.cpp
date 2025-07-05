#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+10;
long long n,q,T,v[N],mn[N],a[3],b[3];
vector <int> edge[N];
long long f[21][N],dep[N];
long long dis[21][N][3][3];
void dfs(int k,int fa){
	dep[k]=dep[fa]+1;
	f[0][k]=fa;
	for(int i=1;i<=20;i++)
		f[i][k]=f[i-1][f[i-1][k]];
	if(T==1){
		dis[0][k][0][0]=v[fa];
	}
	if(T==2){
		dis[0][k][0][0]=dis[0][k][1][0]=v[fa];
		dis[0][k][0][1]=0;
	}
	if(T==3){
		dis[0][k][0][0]=dis[0][k][1][0]=dis[0][k][2][0]=v[fa];
		dis[0][k][0][1]=dis[0][k][1][2]=0;
		dis[0][k][2][2]=mn[k];
	}
	for(int i=1;i<=20;i++)
		for(int x=0;x<T;x++)
			for(int y=0;y<T;y++)
				for(int z=0;z<T;z++)
					dis[i][k][x][z]=min(dis[i][k][x][z],dis[i-1][k][x][y]+dis[i-1][f[i-1][k]][y][z]);
	for(int i=0;i<(int)edge[k].size();i++){
		if(edge[k][i]==fa)continue;
		dfs(edge[k][i],k);
	}
	return ;	
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[i][x]]>=dep[y])
			x=f[i][x];
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(f[i][x]!=f[i][y])
		{
			x=f[i][x];
			y=f[i][y];
		}
	return f[0][x];
}
void solve(int x,int y,int l){
	long long temp[3];
	a[0] = a[1] = a[2] = v[x];
	b[0] = b[1] = b[2] = v[y];
	for(int i=20;i>=0;i--){
		if(dep[f[i][x]]<dep[l])continue;
		memcpy(temp,a,sizeof(a));
		a[0] = a[1] = a[2] = 1e18;
		for(int j=0;j<T;j++)
			for(int k=0;k<T;k++)
				a[k]=min(a[k],temp[j]+dis[i][x][j][k]);
		x=f[i][x];
	}
	for(int i=20;i>=0;i--){
		if(dep[f[i][y]]<dep[l])continue;
		memcpy(temp,b,sizeof(temp));
		b[0]=1e18,b[1]=1e18,b[2]=1e18;
		for(int j=0;j<T;j++)
			for(int k=0;k<T;k++)
				b[k]=min(b[k],temp[j]+dis[i][y][j][k]);
		y=f[i][y];
	}
	return ;
}
long long Ans(int x,int y){
	int l=lca(x,y);
	long long ans=1e18;

	solve(x,y,l);
	ans=min(ans,a[0]+b[0]-v[l]);
	for(int i=0;i<T;i++)
		for(int j=0;j<T;j++)
			ans=min(ans,a[i]+b[j]+(mn[l]*(i+j>T)));
	return ans;
}
int main(){
	//freopen("in","r",stdin);
	cin>>n>>q>>T;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		mn[i]=v[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
		mn[x]=min(mn[x],v[y]);
		mn[y]=min(mn[y],v[x]);
	}
	memset(dis,1, sizeof(dis));
	dfs(1,0);
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<Ans(s,t)<<endl;
	}
	return 0;
}
