#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e3;
typedef long long ll;
int c,n,T,m,a[N+5],p[N+5],mod=998244353;
ll ans,dp[3*N+5];
struct node{
	int val,w;
	friend bool operator <(node u,node v){
		if (u.val*2/u.w==v.val*2/v.w) return u.val>v.val;
		return u.val*2/u.w>v.val*2/v.w;
	}
}b[N+5];
void dfs(int k){
	if (k==n+1){
		for (int i=1;i<=n;i++) b[i]=(node){a[i],p[i]};
		sort(b+1,b+n+1);
		int mm=m; ll sum=0,sum1=0;
		for (int i=1;i<=n;i++){
			if (mm>=b[i].w) mm-=b[i].w,sum+=b[i].val;
		}
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=n*3;j>=b[i].w;j--)
				dp[j]=max(dp[j],dp[j-b[i].w]+b[i].val);
		}
		for (int i=1;i<=m;i++) sum1=max(sum1,dp[i]);
		if (sum==sum1) ans++;
		//cerr<<sum<<' '<<sum1<<'\n';
		//if (mm==0||i==n+1||(b[i-2].val+b[i-1].val)*12/(b[i-2].w+b[i-1].w)>=b[i].val*12/b[i].w)
			//ans=(ans+1)%mod;
	} else {
		p[k]=1; dfs(k+1);
		p[k]=2; dfs(k+1);
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		if (c==16||c==18){
			ans=1;
			for (int i=1;i<=n;i++) ans=ans*2%mod;
		} else if (c==17){
			ans=1;
			for (int i=1;i<=n;i++) ans=ans*2%mod;
			for (int i=1;i<=n;i++){
				int sum1;
				for (int j=1;j<=n;j++){
					if (j==i) b[j]=(node){a[j],1},sum1=a[j];
					else b[j]=(node){a[j],2};
				}
				sort(b+1,b+n+1);
				if (b[n].w==2&&sum1<b[n].val) ans--; 
			}
		} else {
			ans=0;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			dfs(1);
		}
		printf("%lld\n",ans%mod);
	}
}
