#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,M=998224353;
int T,C,n,m,a[N],w[N],ans=0;
struct candy{
	int a,w,id;
	double b;
}c[N];
bool cmp1(candy x,candy y) {
	if(x.b==y.b&&x.a==y.a)return x.id<y.id;
	if(x.b==y.b)return x.a>y.a;
	return x.b>y.b;
}
bool cmp(int x,int y){
	return x>y;
}
bool check(){
	int t=m,ok[N]={1};
	ll sum=0,dp[N]={0},ma=0;
	for(int i=1;i<=n;i++){
		for(int j=m-w[i];j>=0;j--){
			if(ok[j]){
				ok[j+w[i]]=1;
				dp[j+w[i]]=max(dp[j+w[i]],dp[j]+a[i]);
			}
		}
	}
	for(int j=1;j<=m;j++)ma=max(ma,dp[j]);
	for(int i=1;i<=n;i++){
		c[i].a=a[i];
		c[i].w=w[i];
		c[i].b=a[i]/w[i]*1.0;
		c[i].id=i;
	}
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n&&t>0;i++){
		if(c[i].w<=t){
			t-=c[i].w;
			sum+=c[i].a;
		}
	}
	return (sum==ma);
}
void dfs(int now){
	if(now>n){
		if(check())ans++;
		return ;
	}
	w[now]=1;
	dfs(now+1);
	w[now]=2;
	dfs(now+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(m==2*n-1){
			ans=1;
			for(int i=1;i<=n;i++)ans=(1ll*ans*2)%M;
			cout<<(ans-1)%M<<endl;
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
	}
}
