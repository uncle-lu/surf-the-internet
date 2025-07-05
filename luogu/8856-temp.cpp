#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdio>
#define md 998244353
#define int long long
using namespace std;
int f[2002][2002];
int n,m,c,ff;
int mp[2002][2002];
signed main(){
	int t,id;
	cin>>t>>id;
	while(t>0){
		memset(f, 0, sizeof(f));
		memset(mp, 0, sizeof(mp));
		t--;
		cin>>n>>m>>c>>ff;
		for(int i=1;i<=n;i++){
			getchar();
			char w[10001];
			cin>>w;
			for(int j=0;j<=m-1;j++){
				if(w[j]=='0') mp[i][j+1]=1;
				else mp[i][j+1]=0;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(mp[i][j]==0) continue;
				f[i][j]=f[i][j+1]+mp[i][j];
			}
		}
		int asc=0,asf=0;
		for(int j=1;j<m;j++){
			int cc=0,cf=0;
			for(int i=1;i<=n;i++){
				if(f[i][j]==0){
					cc=0;
					cf=0;
					continue;
				}
				asf=(asf+cf)%md;
				cf+=(f[i][j]-1)*cc;
				asc=(asc+(f[i][j]-1)*cc%md)%md;
				int gg=f[i-1][j]-1;
				int fff=0;
				cc+=max(fff,gg);
			}
		}
		cout<<(c*asc%md)%998244353<<" "<<(ff*asf%md)%998244353<<endl;
	}
}
