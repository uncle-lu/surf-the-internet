#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+10;
const int M=1e6+10;
long long n,m,dfn[N],low[N],dn=0,cnt=0,fn[N],fm[N],bl[N],root,s[N],ans;
long long head[2*M],v[2*M],nxt[2*M],tot=0;
long long top=0,sta[N];
long long f[N][2],mod=1e9+7;
vector <int> edge[N];
void add(int x,int y){
	v[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	return ;
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++dn;
	sta[++top]=x;
	for(int i=head[x];i;i=nxt[i]){
		int y=v[i];
		if(y==fa)continue;
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		cnt++;
		int z;
		do{
			z=sta[top--];
			fn[cnt]++;
			bl[z]=cnt;
		}while(z!=x);
	}
	return ;
}
long long fpow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1){
			ans*=x;
			ans%=mod;
		}x=(x*x)%mod;
		k/=2;
	}
	return ans%mod;
}
void dfs(int x,int fa){
	f[x][1]=(fpow(2,fn[x]+fm[x])+mod-fpow(2,fm[x]))%mod;
	f[x][0]=(fpow(2,fm[x])+mod)%mod;
	s[x]=fm[x];
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i];
		if(y==fa)continue;
		dfs(y,x);
		s[x]+=s[y]+1;
		f[x][1]=(f[x][0]*f[y][1] % mod + f[x][1]*(2*f[y][0]+f[y][1]) % mod + f[x][1])%mod;
		f[x][0]=f[x][0]*f[y][0]%mod;
	}
	return ;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j]){
			int y=v[j];
			if(bl[y]==bl[i])fm[bl[i]]++;
			else {
				edge[bl[i]].push_back(bl[y]);
			}
		}
	}
	for(int i=1; i<=cnt; i++)
		fm[i]/=2;
	dfs(1,0);
	for(int i=2;i<=cnt;i++){
		ans=(ans + fpow(2,s[1]-s[i]-1)*f[i][1] % mod ) % mod;
	}
	ans+=f[1][1];
	cout<<ans%mod<<endl;
	return 0;
}
