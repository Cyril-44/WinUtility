#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,cost,a[N],b[N],ans=0,al=0,no=0;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cost=2e18;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i],&b[i]);
		cost=min(cost,a[i]+b[i]);
	}
	sort(a+1,a+n+1);
	ans=m/cost*2;
	for(int i=1;i<=n;i++){
		al+=a[i],no++;
		if(al>m)break;
		ans=max(ans,no+(m-al)/cost*2);
	}
	cout<<ans;
	return 0;
}