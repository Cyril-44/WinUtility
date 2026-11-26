#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
long long cs,t,n,m,c[5005];

void read(long long &res){
	res=0;long long flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	res*=flag;
	return;
}

long long fpow(long long x,int y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;y>>=1;
	}
	return res%mod;
}

struct node{
	long long w,id;
	long double v;
}a[5005];
long long cnt,dp[5005];

bool cmp(node a,node b){
	if(a.v==b.v){
		if(a.w==b.w) return a.id<b.id;
		return a.w>b.w;
	}
	return a.v>b.v;
}

bool check(){
	long long res=0;
	for(int i=1;i<=n;i++) a[i].v=c[i]*1.0/a[i].w;
	for(int i=1;i<=n;i++) a[i].id=i;
	sort(a+1,a+n+1,cmp);long long ct=0;
	for(int i=1;i<=n;i++) 
		if(a[i].w+ct<=m) res+=c[a[i].id],ct+=a[i].w;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=m;j>=a[i].w;j--)
			dp[j]=max(dp[j],dp[j-a[i].w]+c[a[i].id]);
	for(int i=0;i<=m;i++)
		if(res<dp[i]) return false;
	return true;
}

void calc(){
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++)
			a[j].w=((i>>(j-1))&1)+1;
		cnt+=check();
	}
	return;
}

void solve_min(){
	cnt=0;calc();
	printf("%lld\n",cnt);
}

void solve_A(){
	printf("%lld\n",fpow(2,n));
}

bool cmp1(node a,node b){
	if(a.v==b.v) return a.id<b.id;
	return a.v>b.v;
}

bool cmp2(node a,node b){
	if(a.v*2==b.v) return 0;
	return a.v*2>b.v;
}

void solve_m(){
	for(int i=1;i<=n;i++)
		a[i].v=c[i],a[i].id=i;
	sort(a+1,a+n+1,cmp1);
//	for(int i=1;i<=n;i++)
//		printf("%9Lf %lld\n",a[i].v,a[i].id);
//	cout<<endl;
	long long res=1;
	for(int i=2;i<=n;i++)
		if(!cmp2(a[i],a[1])) res=(res*2)%mod;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(cmp2(a[j],a[1]))
				res=(res+fpow(2,n-j))%mod/*,cout<<i<<" "<<j<<" "<<fpow(2,n-j)<<endl*/;
		}
	printf("%lld\n",res);
	return;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	read(cs);read(t);
	while(t--){
		read(n);read(m);
		for(int i=1;i<=n;i++)
			read(c[i]);
		if(cs<=5) solve_min();
		else if(m==2) solve_m();
		else solve_A();
	}
	return 0;
}
