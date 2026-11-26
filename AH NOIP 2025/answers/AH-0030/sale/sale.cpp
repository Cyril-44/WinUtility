#include <cstdio>
#include <algorithm>
using namespace std;

int c,t,n,m,mod=998244353;
int a[5005];
long long kuai(long long a,long long b){
	if(b==1) return a%mod;
	if(b==0) return 1;
	if(b%2==1) return (kuai(a,b/2)%mod*kuai(a,b/2)*mod*a%mod)%mod;
	else return (kuai(a,b/2)%mod*kuai(a,b/2)%mod)%mod;
}
bool cmp(int x,int y) {
	return x>y;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1,cmp);
		if(m==2*n-1) printf("%lld\n",kuai(2,1ll*n));
		else printf("%lld\n",kuai(2,1ll*(n-1)));
	}
	return 0;
}
