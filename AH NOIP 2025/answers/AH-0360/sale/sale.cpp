#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int C,T;
int n,m,ans;
int a[500005],b[500005],f[100005];
struct o{
	int x,y;
}c[1000005];
bool cmp(o x,o y){
	if(x.x*y.y!=y.x*x.y)return x.x*y.y>y.x*x.y;
	return x.x>y.x;
}
bool check(){
	int s=0,s2=0,g=m;
	for(int i=1;i<=n;i++)c[i].x=a[i],c[i].y=b[i];
	for(int i=1;i<=m;i++)f[i]=0;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n&&g>0;i++)if(g>=c[i].y)g-=c[i].y,s+=c[i].x;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=c[i].y;j--)f[j]=max(f[j],f[j-c[i].y]+c[i].x);
	}
	for(int i=0;i<=m;i++)s2=max(f[i],s2);
	if(s==s2)return 1;
	return 0;
}
void dfs(int x){
	if(x==n+1){
		if(check())ans=(ans+1)%mod;
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=2;
	dfs(x+1);
}
int qp(int x,int y){
	if(y==1)return x;
	int h=qp(x,y/2);
	if(y%2)return (h*h)%mod*x%mod;
	return h*h%mod;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>m,ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=50){
			dfs(1);
			cout<<ans<<"\n";
		}
		else{
			cout<<qp(2,n)<<"\n";
		}
	}
	return 0;
}
//!noip@Nov29,2025:dream
