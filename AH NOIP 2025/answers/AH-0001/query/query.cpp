#include<bits/stdc++.h>
using namespace std;
const int Maxn=50005,Maxlog=19;
int n,q,logg[Maxn];
typedef long long ll;
ll a[Maxn],st[Maxlog][Maxn],ans[Maxn];
unsigned long long res;
ll query(int l,int r){int k=logg[r-l+1];return min(st[k][l],st[k][r-(1<<k)+1]);}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	logg[0]=-1;for(int i=1;i<=n;++i) logg[i]=logg[i>>1]+1;
	for(int i=1;i<=n;++i){scanf("%lld",a+i);a[i]+=a[i-1];}
	for(int i=0;i<=n;++i){st[0][i]=a[i];}
	for(int i=1;(1<<i)<=n+1;++i) for(int j=0;j+(1<<i)-1<=n;++j){
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	scanf("%d",&q);
	for(int t=1,l,r;t<=q;++t){
		scanf("%d%d",&l,&r);res=0;
		for(int i=1;i<=n;++i){
			ans[i]=-1e18;
			for(int j=max(i,l);j<=i+r-1&&j<=n;++j) 
				ans[i]=max(ans[i],a[j]-query(max(0,j-r),min(i-1,j-l)));
			res^=(unsigned long long)(ans[i])*i;
		}
		printf("%llu\n",res);
	}
	return 0;
}
