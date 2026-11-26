#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long p=998244353;
int c,t,n; long long dp[N];
int m; long long cnt;
struct node {long long a,v;int w;} x[N],y[N];
bool cmp(node x,node y) {
    if(x.v!=y.v) return x.v>y.v;
    return x.a>y.a;	
}
bool cmp2(node x,node y) {
	return x.a>y.a;
}
void dfs(int step) {
    if(step==n+1) {
		for(int i=1;i<=m;i++) dp[i]=0;
		for(int i=1;i<=n;i++) {
		    for(int j=m;j>=x[i].w;j--) {
			    dp[j]=max(dp[j],dp[j-x[i].w]+x[i].a);	
			}	
		}
		for(int i=1;i<=n;i++) {
		    y[i].a=x[i].a,y[i].w=x[i].w,y[i].v=x[i].v;	
		}
		sort(y+1,y+n+1,cmp);
		int tmp=m; long long sum=0;
		for(int i=1;i<=n;i++) {
		    if(tmp>=y[i].w) tmp-=y[i].w,sum+=y[i].a;
		}
		if(sum==dp[m]) cnt=(cnt+1)%p;
		return;
	}
	x[step].w=1,x[step].v=x[step].a*2; dfs(step+1);
	x[step].w=2,x[step].v=x[step].a; dfs(step+1);	
}
int main() {
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--) {
		cnt=0;
	    scanf("%d %d",&n,&m);
	    for(int i=1;i<=n;i++) scanf("%lld",&x[i].a);
	    for(int i=1;i<=n;i++) x[i].v=0,x[i].w=0;
	    if(c==18) {
			long long s=1;
		    for(int i=1;i<=n;i++) s=(s*2)%p;
		    printf("%lld\n",s);
		}
		else if(c>=0&&c<=5) {
		    dfs(1);
		    printf("%lld\n",cnt);
		}
	}
    return 0;
}
