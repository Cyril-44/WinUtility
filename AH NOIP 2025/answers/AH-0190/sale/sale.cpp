#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int pow(int a,int b){
	int ans=1,base=a;
	while(b>0){
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return ans;
}
int n,m;
int t;
struct node{
	double x;
	int y;
	int z;
};
node b[10005];
int a[10005],w[10005];
int f[1005][1005];
int bag(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			if(j-w[i]>=0){
				f[i][j]=max(f[i][j],f[i-1][j-w[i]]+a[i]);
			}
		}
	}
	return f[n][m];
}
bool cmp(node x,node y){
	if(x.x==y.x) return x.y>y.y;
	return x.x>y.x;
}
int xjb(){
	memset(b,0,sizeof(b));
	int ans=0;
	int f=m;
	for(int i=1;i<=n;i++){
		b[i].x=(double)(a[i])/(double)(w[i]);
		b[i].y=a[i];
		b[i].z=w[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(f>=b[i].z){
			f-=b[i].z;
			ans+=b[i].y;
		}
		if(f<=0) break;
	}
	return ans;
}
int cnt;
void dfs(int s){
	if(s>=n+1){
		if(bag()==xjb()){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	w[s]=1;
	dfs(s+1);
	
	w[s]=2;
	dfs(s+1);
}
int c;
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(w,0,sizeof(w));
		cnt=0;
		cin>>n>>m;
		bool ok=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]!=a[i-1]&&i>=2) ok=0;
		}
		if(ok){
			int ans=pow(2,n);
			printf("%lld\n",ans);
			continue;
		}
		dfs(1);
		printf("%lld\n",cnt);
	}
	
	
	return 0;
}
