#include<iostream>
#include<cstring>
using namespace std;
long long n,m,a[105][2005],sum[105],f[105][205],g[105][105],mod=998244353,ans;
int main(){
	//freopen("in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sum[i]=(sum[i]+a[i][j])%mod;
		}
	}
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		g[i][0]=1;
		for(int j=1;j<=i;j++){
			g[i][j]=(g[i-1][j]+g[i-1][j-1]*sum[i])%mod;
		}
	}
	for(int j=1;j<=n;j++) ans=(ans+g[n][j])%mod;
	for(int c=1;c<=m;c++){
		memset(f,0,sizeof(f));
		f[0][n] = 1;
		for(int i=1;i<=n;i++){
			for(int j=n-i;j<=n+i;j++){
				f[i][j]=(f[i-1][j]+f[i-1][j-1]*a[i][c]+(sum[i]-a[i][c])*f[i-1][j+1])%mod;
			}
		}
		for(int j=1;j<=n;j++) ans=(ans-f[n][n+j]+mod)%mod;
	}
	cout<<ans;
	return 0;
}
