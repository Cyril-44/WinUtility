#include<bits/stdc++.h>
using namespace std;
int n,a[50005],q;
long long sum[50005];
long long as[50005];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	scanf("%d",&q);
	while(q--){
		for(int i=1;i<=n;i++)
			as[i]=-1000000000000000;
		int L,R;
		scanf("%d%d",&L,&R);
		for(int i=1;i+L-1<=n;i++)
			for(int j=i+L-1;j<=R+i-1&&j<=n;j++)
				for(int k=i;k<=j;k++)
					as[k]=max(as[k],sum[j]-sum[i-1]);
		unsigned long long ans=0,op=0;
		for(int i=1;i<=n;i++){
			op=i*as[i];
			if(op<0)op=op+(1ll<<63)+(1ll<<63);
			ans^=op;
		}
		printf("%llu\n",ans);
	}
    return 0;
}
/*!noip@Nov29,2025:dream*/
