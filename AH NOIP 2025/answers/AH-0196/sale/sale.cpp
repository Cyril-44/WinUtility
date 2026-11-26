#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int t,n,m,cnt=0,ans=0,C;
int a[10005],b[10005];
struct st{
	int yj,id;
	double xjb;
}c[10005];
long long ksm(int x,int k){
	long long s=1,l=x;
	while(k){
		if(k%2==1) s=s*l%mod;
		l=l*l%mod;
		k/=2;
	}
	return s;
}
bool cmp(int x,int y){
	return x>y;
}
bool cmp2(st x,st y){
	if(x.xjb==y.xjb) return x.yj>y.yj;
	return x.xjb>y.xjb;
}
long long f[10000];
void dfs(int x){
	if(x==n+1){
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			c[i].xjb=a[i]*1.0/(b[i]*1.0);
			c[i].yj=a[i];
			c[i].id=i;
		}
		sort(c+1,c+n+1,cmp2);
		long long s=0;
		int mx=m;
		for(int i=1;i<=n;i++){
			if(mx==0) break;
			mx-=b[c[i].id];
			s+=c[i].yj;
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=b[i];j--) f[j]=max(f[j],f[j-b[i]]+a[i]);
		}
		if(s>=f[m]) ans=(ans+1)%mod;
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=2;
	dfs(x+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		mn=0,cnt=0,ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			 scanf("%d",&a[i]);
			 if(a[i]==a[i-1]) cnt++;
		}
		if(cnt==n-1||m>n){
			cout<<ksm(2,n*1ll);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		if(n<=30){
			dfs(1);
			cout<<ans<<endl;
			continue;
		}else cout<<(ksm(2,n)+mod-ksm(2,n-m/2))%mod;
	}
	
}
