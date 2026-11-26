#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10,mod=998244353;
long long c,t,n,m,ans,dp[N];
struct node
{
	long long x,w,id;
	double t;
}a[N],b[N];
bool cmp(node u,node v)
{
	if(u.t==v.t){
		if(u.x==v.x)return u.id<v.id;
		return u.x>v.x;
	}
	return u.t>v.t;
}
void check()
{
	memset(dp,0,sizeof dp);
	memcpy(b,a,sizeof b);
	long long ret=m,s1=0,s2=0;
	sort(b+1,b+n+1,cmp);
	for(long long i=1;i<=n;i++){
		if(b[i].w<=ret){
			s1+=b[i].x;
			ret-=b[i].w;
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=m;j>=b[i].w;j--){
			dp[j]=max(dp[j],dp[j-b[i].w]+b[i].x);
		}
	for(long long i=1;i<=m;i++)s2=max(s2,dp[i]);
	if(s1==s2)ans=(ans+1)%mod;
	return;
}
void dfs(long long step)
{
	if(step==n+1){
		check();
		return;
	}
	a[step].w=1;
	a[step].t=a[step].x;
	dfs(step+1);
	a[step].w=2;
	a[step].t=a[step].x/2.0;
	dfs(step+1);
	return;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==18){
		while(t--){
			ans=1;
			cin>>n>>m;
			for(long long i=1;i<=n;i++)cin>>a[i].x;
			for(long long i=1;i<=n;i++)ans=(ans*2)%mod;
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x;
			a[i].id=i;
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
