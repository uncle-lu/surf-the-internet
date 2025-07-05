#include<iostream>
using namespace std;
const int N=1e5+10,M=3e5+10; 
int n,m,a[N],dn=0,dfn[N],low[N],sta[N],top=0,d[N];
int head[N],ver[M],nxt[M],tot=0;
int hc[N],vc[M],nc[N],tc=0;
int scc=0,val[N],v[N],in[N],out[N],q=0,flg=0;
bool vis[N],vis2[N];
void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	return ;
}
void add_c(int x,int y){
	vc[++tc]=y;
	nc[tc]=hc[x];
	hc[x]=tc;
	return ;
}
void tarjan(int x){
	dfn[x]=low[x]=++dn;
	sta[++top]=x;
	vis[x]=true;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(vis[y]) low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		scc++;
		int z;
		do{
			z=sta[top--];
			vis[z]=false;
			v[z]=scc;
			val[scc]++;
		}while(x!=z);
	}
	return ;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j]){
			int y=ver[j];
			if(v[i]==v[y]||vis2[v[y]])continue;
			add_c(v[i],v[y]);
			vis[v[y]]=true;
			in[v[y]]++;
		}
		for(int j=head[i];j;j=nxt[j]){
			int y=ver[j];
			vis[v[y]]=false;
		}
	}
	for(int i=1;i<=scc;i++){
		if(!in[i]){
			q++;
			bool flag=true;
			for(int j=hc[i];j;j=nc[j]){
				if(in[vc[j]]==1)flag=false;
			}
			if(flag&&val[i]==1)flg=1;
		}
	}
	printf("%.6lf",1.0*(n-q+flg)/n);
	return 0;
}
