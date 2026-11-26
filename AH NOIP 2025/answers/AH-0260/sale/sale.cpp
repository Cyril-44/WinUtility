#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MN=5010,mod=998244353;
typedef long long ll;
int n,m;
int a[MN];
bool cmp(int a1,int a2){
	return a1>a2;
}
ll qpow(ll num,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*num%mod;
		num=num*num%mod;
		k>>=1;
	}
	return res;
}
int dp[MN];
typedef struct S{
	int p;
	double num;
	int re;
	int w;
	bool operator <(const S &rhs)const{
		if(num==rhs.num) return p<rhs.p;
		return num>rhs.num;
	}
}S;

S b[MN];
int bb(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		for(int j=m;j>=b[i].w;--j){
			dp[i]=max(dp[i],dp[i-b[i].w]+b[i].re);
		}
	}
	return dp[m];
}
bool solve(ll sta){
	for(int i=1;i<=n;++i){
		if(sta&(1<<i)){
			b[i].p=i;
			b[i].num=a[i]/2.0;
			b[i].w=2;
		}else{
			b[i].p=i;
			b[i].num=a[i];
			b[i].w=1;
		}
		b[i].re=a[i];
	}
	int bz=bb();
	int money=m,sum=0;
	for(int i=1;i<=n;++i){
		if(money>=b[i].w){
			money-=b[i].w;
			sum+=b[i].re;
		}
	}
	//printf("%lld %d %d\n",sta,bz,sum);
	return (bz==sum);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	for(ll sta=0;sta<=(1ll<<n);++sta){
		if(solve(sta))++ans;
	}
	while(ans<0)ans+=mod;
	printf("%lld\n",ans);
	return 0;
}
