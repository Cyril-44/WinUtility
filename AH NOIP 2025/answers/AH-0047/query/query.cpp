#include<bits/stdc++.h>
using namespace std;
long long n,q,a[50005],sum[50005],dp[3005][3005],l,r;
unsigned long long cnt,ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]+=a[i];
	if(n<=3000){
		cin>>q;
		while(q--){
			ans=0;
			scanf("%lld%lld",&l,&r);
			for(int i=1;i<=n;i++){
				cnt=0;
				for(int j=l;j<=r;j++){
					for(int k=i-j;k<i;k++){
						cnt=max(cnt,(unsigned long long)sum[k+j]-sum[k]);
					}
				}
				ans^=cnt;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
 4
 2 4 -5 1
 3
 1 2
 3 4
 1 4
 */
