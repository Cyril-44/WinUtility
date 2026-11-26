#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=5e4+5;
const ll inf=1e18;
int n,a[N],q;
ll ans[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	cin>>q;
	while(q--){
		int l,r;
		for(int i=1;i<=n;i++)ans[i]=-inf;
		scanf("%d%d",&l,&r);
		for(int len=l;len<=r;len++){
			ll sum=0;
			for(int i=1;i<len;i++)sum+=a[i];
			for(int i=len;i<=n;i++){
				int j=i-len+1;
				sum+=a[i];
				sum-=a[j-1];
				for(int k=j;k<=i;k++)ans[k]=max(ans[k],sum);
			}
		}
		//for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		ull pl=0;
		for(int i=1;i<=n;i++){
			if(ans[i]<0){
				ull k=ans[i];
				pl^=k*i;
			}else pl^=(ull)ans[i]*i;
		}
		printf("%llu\n",pl);
	}
	return 0;
}
