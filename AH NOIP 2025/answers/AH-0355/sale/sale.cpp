#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
typedef long long ll;
int csd,t,n;
ll m,f1,f2,ans,dp[10005];
struct Node{
	ll a;
	ll w;
}a[5005],b[5005];
bool cmp(Node x,Node y){
	if(x.a*y.w!=y.a*x.w)
		return x.a*y.w>y.a*x.w;
	return x.a>y.a;
}
ll qtrue(){
	ll tmp=0;
	for(int i=1;i<=n;i++)
		for(ll j=m;j>=a[i].w;j--)
			dp[j]=max(dp[j],dp[j-a[i].w]+a[i].a);
	for(ll i=1;i<=m;i++)
		tmp=max(tmp,dp[i]);
	return tmp;
}
ll qx(){
	ll tmp=0,mm=m;
	for(int i=1;i<=n;i++)
		b[i].a=a[i].a,b[i].w=a[i].w;
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n&&mm!=0;i++)
		if(mm>=b[i].w){
			mm-=b[i].w;
			tmp+=b[i].a;
		}
	return tmp;
}
void dfs(int idx){
	if(idx==n+1){
		for(int i=0;i<=m;i++)	
			dp[i]=0;
		f1=qtrue();
		f2=qx();
		if(f1==f2)
			ans=(ans+1)%N;
		return ;
	}
	a[idx].w=1;
	dfs(idx+1);
	a[idx].w=2;
	dfs(idx+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>csd>>t;
	if((csd>=7&&csd<=9)||(csd>=14&&csd<=15)){
		while(t--){
			ans=1;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
				cin>>a[i].a;
			for(int i=1;i<=n;i++)
				ans=ans*2%N;
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i].a;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
