#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 50010;
ll a[N],sum[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int L,R;
		ll ans = 0ll;
		scanf("%d%d",&L,&R);
		for(int i=1;i<=n;i++){
			ll s = -999999999;
			for(int len=L;len<=R;len++){
				for(int j=max(1,i-len+1);j<=i && j+len-1<=n;j++){
					s = max(s, sum[j+len-1] - sum[j-1]);
				}
			}
			ans = (ans^((i*1ll*s)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
