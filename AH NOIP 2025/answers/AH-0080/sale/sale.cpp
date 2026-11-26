#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+25,p=998244353;
ll a[N];
ll quick(ll y){
	if(y==0)return 1;
	if(y==1)return 2;
	ll t=quick(y>>1);
	t=t*t%p;
	if(y&1)t=t*2%p;
	return t;
}
ll b[N];
ll f[105][105];
ll pac(ll n,ll m){
	ll i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)f[i][j]=0;
	for(i=1;i<=n;i++)
		for(j=m;j>=1;j--)
			if(j<b[i])f[i][j]=f[i-1][j];
			else
			f[i][j]=max(f[i-1][j],f[i-1][j-b[i]]+a[i]);
	return f[n][m];
}
struct node{
	ll x, y;
}tmp[N];
bool cmp(node u,node v){
	if(u.x*v.y!=u.y*v.x)return u.x*v.y>u.y*v.x;
	return u.x>v.x;
}
ll sol(ll n,ll m){
	ll i,ans=0;
	for(i=1;i<=n;i++)tmp[i]={a[i],b[i]};
	sort(tmp+1,tmp+n+1,cmp);
	for(i=1;i<=n;i++)
		if(m>=tmp[i].y)ans+=tmp[i].x,m-=tmp[i].y;
	return ans;
}
void solve1(){//1-5
	ll n,m,i,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	ll w,res=(1<<n)-1;
	for(ll ww=0;ww<=res;ww++){
		w=ww;
		for(i=1;i<=n;i++)b[i]=(w&1)+1,w>>=1;
		ll t1=pac(n,m),t2=sol(n,m);
		//cout<<t1<<' '<<t2<<'\n';
		if(t1==t2)ans=(ans+1)%p;
	}
	cout<<ans<<'\n';
}
void solve2(){//7-9
	ll n,m,i,ans=0,c=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=n;i>=1&&a[i]==a[n];i--);
	c=n-i;
	ll pos=i;
	ans=(quick(c)-1+p)*quick(n-c)%p;
	for(i=1;i<=pos;i++)
		for(ll j=i+1;j<=pos;j++)
			if(a[n]>=2*a[j]||a[i]+a[j]>=a[n])ans=(ans+quick(i-1))%p;
	for(i=1;i<=pos;i++)
		if(a[n]>=2*a[i])ans=(ans+1)%p;
	ans=(ans+1)%p;
	cout<<ans<<'\n';
}
void solve3(){//17
	ll n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll num=1;
	for(i=1;i<=n;i++)num=(num*2)%p;
	if(2*a[1]<=a[2]||a[1]==a[2])cout<<num<<'\n';
	else cout<<(num-1+p)%p<<'\n';
}
/*ll dp[325][325];
void solve4(){
	
}*/
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll opt,t;
	cin>>opt>>t;
	while(t--){
		if(opt<=5)solve1();
		else
		if((opt>=7&&opt<=9)||(opt==14||opt==15))solve2();
		else
		if(opt==17)solve3();
		else
		if(opt==16||opt==18){
			ll w,n,m,i;
			cin>>n>>m;
			for(i=1;i<=n;i++)cin>>w;
			w=1;
			for(i=1;i<=n;i++)w=w*2%p;
			cout<<w<<'\n';
		}
		else{
			ll w,n,m,i;
			cin>>n>>m;
			for(i=1;i<=n;i++)cin>>w;
			w=1;
			for(i=1;i<=n;i++)w=w*2%p;
			cout<<w<<'\n';
		}
	}
	return 0;
}
