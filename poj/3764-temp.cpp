#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1e5+10;
int n,d[N],trie[N*32][2],cnt,ans;
struct node {
	int t,v;
};
void dfs(int x,int fa){
	for(int i=0;i<(int)edge[x].size();i++){
		int to=edge[x][i].t,val=edge[x][i].v;
		if(to!=fa){
			d[to]=val^d[x];
			dfs(to,x);
		}
	}
	return ;
}
void search(int x){
	int p=0;
	for(int i=31;i>=0;i--){
		if(trie[p][x>>i&1]==0)trie[p][x>>i&1]=++cnt;
		p=trie[p][x>>i&1];
	}
	return ;
}
int sum(int x){
	int p=0,an=0;
	for(int i=31;i>=0;i--){
		int t=(x>>i)&1;
		if(trie[p][t^1]!=0){
			an+=1<<i;
			p=trie[p][t^1];
		}else{
			p=trie[p][t];
		}
	}
	return an;
}
int main(){
	while(cin>>n){
		ans=0,cnt=0;
		memset(d,0,sizeof(d));
		memset(trie,0,sizeof(trie));
		for(int i=1;i<n;i++){
			int x,y,val;
			scanf("%d%d%d",&x,&y,&val);
			edge[x].push_back((node){y,val});
			edge[y].push_back((node){x,val});
		}
		dfs(0,-1, edge[N]);
		search(d[0]);
		for(int i=1;i<n;i++){
			ans=max(ans,sum(d[i]));
			search(d[i]);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
