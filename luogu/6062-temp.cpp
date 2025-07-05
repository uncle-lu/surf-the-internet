#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,m,mp[55][55],cntr=0,cntc=0,ma[2600],ans;
bool a[55][55],vis[2600];
vector <int> edge[2600];
bool dfs(int x){
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i];
		if(vis[y])continue;
		vis[y]=true;
		if(!ma[y]||dfs(ma[y])){
			ma[y]=x;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
		    cin>>c;
			if(c=='*')a[i][j]=true;
		}    
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				cntr++;
				do {
					mp[i][j] = cntr;
					j++;
				}while(a[i][j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]){
				cntc++;
				do {
					edge[mp[j][i]].push_back(cntc);
					j++;
				}while(a[j][i]);
			}
		}
	}
	for(int i=1;i<=cntr;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
