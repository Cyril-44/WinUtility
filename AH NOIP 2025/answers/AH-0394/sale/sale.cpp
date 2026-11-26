#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
int c,T,a[N],n,m,vis[N];
ll res;
struct node{
	double b;
	int va,u;
}t[30];
bool cmp(node u,node v){
	return u.b<v.b;
}
void dfs(int step){
	if(step==n+1){
		int f[50];
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			t[i].u=a[i];
			t[i].b=a[i]*1.0/vis[i];
			t[i].va=vis[i];
		}
		sort(t+1,t+n+1,cmp);
		for(int i=1;i<=n;i++)
			for(int j=m;j>=vis[i];j--)f[j]=max(f[j],f[j-vis[i]]+a[i]);
		//cout<<f[m]<<' ';
		int ans=0,p=m;
		for(int i=n;i>=1;i--){
			if(p<t[i].va)continue;
			ans+=t[i].u;
			p-=t[i].va;
		}
		if(f[m]==ans)res++;
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=2;
	dfs(step+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	if(c==18){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			ll ans=0;
			for(int i=1;i<=n;i++)ans=(ans*2)%mod;
			cout<<ans<<'\n';
		}
	}else if(c>=1&&c<=5){
		while(T--){
			memset(a,0,sizeof a);
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			dfs(1);
			cout<<res<<'\n';
		}
	}
	return 0;
}
