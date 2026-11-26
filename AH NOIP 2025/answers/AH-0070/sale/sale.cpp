#include<bits/stdc++.h>
#define ll long long 
using namespace std;

inline ll rd(){ll x=0,f=1;char c;c=getchar();while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}while(isdigit(c)){	x=x*10+(c-'0');	c=getchar();}return x*f;}
const int M =5e3+5;
const int mod=998244353;
ll c,t,n,m;
ll a[M],ans;
ll dp[M][2*M],cnt,fac[M],inv[M],num,tmp[M];
bool flag;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans = (ans*a)%mod;
		a = (a*a)%mod;b>>=1;
	}
	return ans%mod;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;i--){
		inv[i]=(inv[i+1]*(i+1))%mod;
	}
}
void solve(){
	n=rd(),m=rd();
	ans=qpow(2,n);
	num=0;
	flag=1;
	for(int i=1;i<=n;i++){
		a[i]=rd();tmp[i]=a[i];
		if(i>=2&&a[i]!=a[i-1]) flag=0;
	}
//	int cnt=0;
	if(flag){
		printf("%lld\n",ans);
		return;
	}
	//sort(tmp+1,tmp+n+1);
	//sort(a+1,a+n+1,greater<ll>());
	printf("%lld\n",ans%mod);
	return ;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	c=rd();t=rd();
	while(t--){
		solve();
	}
	return 0;
}
// wo chang chang zhui yi guo qu
/*#include<bits/stdc++.h>
#define ll long long 
using namespace std;

inline ll rd(){ll x=0,f=1;char c;c=getchar();while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}while(isdigit(c)){	x=x*10+(c-'0');	c=getchar();}return x*f;}

const int M =5e3+5;
const int mod=998244353;
ll o,t,n,m;
ll a[M],ans;
ll dp[M][2*M],cnt,fac[M],inv[M],num,tmp[M];
bool flag;
ll c[10][20];
ll d[10];
struct T{
	double x;
	ll id,w,a;
}e[20];
bool cmp(T x,T y){
	if(x.x!=y.x) return x.x>y.x;
	else{
		if(x.w!=y.w) return x.w>y.w;
		else{
			return x.id<y.id;
		}
	}
}

ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans = (ans*a)%mod;
		a = (a*a)%mod;b>>=1;
	}
	return ans%mod;
}
int check(){
	for(int i=1;i<=n;i++){
	//	cout<<d[i]<<" ";
		e[i].id=i;
		e[i].x=a[i]*1.000/d[i];
		e[i].w=d[i];
		e[i].a=a[i];
	}
//	cout<<endl;
	sort(e+1,e+n+1,cmp);
	ll sum=0,k=m;
	for(int i=1;i<=n;i++){
		if(k>=e[i].w){
			k-=e[i].w;
			sum+=e[i].a;
		}
	}
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++){
		for(int v=m;v>=e[i].w;v--){
			//c[i][v]=max(c[i][v],c[i-1][v]);
			c[i][v] = max(c[i][v],c[i-1][v-e[i].w]+e[i].a);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=min(m-1,n);j<=m;j++)
		ans=max(c[i][j],ans);
	}
	//cout<<ans<<" "<<sum<<endl;
	return sum>=ans;
}
void dfs(int a){
	if(a==n+1){
		if(check()) ans++;
		return;
	}
	else{
		d[a]=1;
		dfs(a+1);
		d[a]=2;
		dfs(a+1);
	}
}
void solve(){
	n=rd(),m=rd();
	num=0;
	flag=1;
	ans=0;
	for(int i=1;i<=n;i++){
		a[i]=rd();tmp[i]=a[i];
		if(i>=2&&a[i]!=a[i-1]) flag=0;
	}
//	int cnt=0;
	if(flag){
		printf("%lld\n",ans);
		return;
	}
	dfs(1);
	printf("%lld\n",ans);
	return ;
}
int main(){
	//freopen("sale.in","r",stdin);
	//freopen("sale.out","w",stdout);
	o=rd();t=rd();
	while(t--){
		solve();
	}
	return 0;
}
!noip@Nov29,2025:dream
*/
