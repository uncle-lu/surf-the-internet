#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m,root,dfn[1005],low[1005],dn=0,cnt=0;
int sta[1005],top=0,now,v[1005],c[1005],ans,able[1005];
int edge[1005][1005];
vector <int> dcc[1005];
void tarjan (int x){
	int flag = 0;
	dfn[x]=low[x]=++dn;
	sta[++top]=x;
	if(x==root&&edge[x][0]==0){
		dcc[++cnt].push_back(x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!edge[x][i])continue;
		if(!dfn[i]){
			tarjan(i);
			low[x]=min(low[x],low[i]);
			if(low[i]>=dfn[x]){
				flag++;
				cnt++;
				int z;
				do{
					z=sta[top--];
					dcc[cnt].push_back(z);
				}while(z!=i);
				dcc[cnt].push_back(x);
			}
		}
		else low[x]=min(low[x],dfn[i]);
	}
	return ;
}
bool dfs(int x,int col){
	c[x]=col;
	for(int i=1;i<=n;i++){
		if((!edge[x][i])||(v[i]!=now))continue;
		if(c[i]&&c[i]==col) return true;
		if(!c[i]) return dfs(i,3-col);
	}
	return false;
}
int main(){
	while(cin>>n>>m&&n){
		dn=0,top=0,cnt=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(c,0,sizeof(c));
		memset(edge,0x3f,sizeof(edge));
		memset(v,0,sizeof(v));
		memset(able,0,sizeof(able));
		for(int i=1;i<=n;i++) edge[i][i]=0,edge[i][0]=n-1;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			edge[x][y]=edge[y][x]=0;
			edge[x][0]--;
			edge[y][0]--;
		}
		
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				root=i;
				tarjan(i);
			}
		}
		
		for(int i=1;i<=cnt;i++){
			now=i;
			for(int j=0;j<(int)dcc[i].size();j++){
				v[dcc[i][j]]=now,c[dcc[i][j]]=0;
			}
			if(dfs(dcc[i][0],1)){
				for(int j=0;j<(int)dcc[i].size();j++) able[dcc[i][j]]=1; 
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) if(!able[i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
