#include <bits/stdc++.h>
using namespace std;

struct edge{
	long long w,v,xuh;
}ar[2001],ar2[1001];

long long c,t,n,m,mod=998244353,ans;
int f[1001][1001];

bool cmp(edge a,edge b){
	double aa=a.w*1.0/(a.v*1.0);
	double bb=b.w*1.0/(b.v*1.0);
	if(aa!=bb) return aa>bb;
	else if(a.w!=b.w) return a.w>b.w;
	else return a.xuh<b.xuh;
}

void pd(){
	memset(f,0,sizeof(f));
	long long cnt=0;
	for(int i=1;i<=n;i++) ar2[i]=ar[i];
	sort(ar2+1,ar2+n+1,cmp);
	long long mm=m;
	for(int i=1;i<=n;i++){
		if(ar2[i].v<=mm){
			mm-=ar2[i].v;
			cnt+=ar2[i].w;
		}
		else if(mm<=0) break;
	}
	for(int i=1;i<=n;i++){
		int xch=ar[i].w;
		for(long long j=1;j<=m;j++){
			if(ar[i].v<=j) f[i][j]=max(f[i-1][j-ar[i].v]+xch , f[i-1][j]);
			else f[i][j]=f[i-1][j];
		}
	}
	if(f[n][m]==cnt) ans++;
	ans%=mod;
}

void dfs(long long tim){
	if(tim==n){
		pd();
		return ;
	}
	tim++;
	ar[tim].v=1;
	dfs(tim);
	ar[tim].v=2;
	dfs(tim);
	ar[tim].v=0;
}

long long ksm(long long a,long long k){
	long long anss=1;
	while(1){
	if(k%2==1) anss=a*anss%mod;
	a=a*a%mod;
	k/=2;
	if(k==1) return anss*a%mod;
	}
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		memset(ar,0,sizeof(ar));
		scanf("%lld%lld",&n,&m);
		bool flag=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&ar[i].w);
			ar[i].xuh=i;
			if(ar[i].w!=ar[i-1].w&&i!=1) flag=0;
		}
		if(flag==1){
			printf("%lld",ksm(2,n));
			continue ;
		}
		dfs(0);
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
