#include<bits/stdc++.h>
using namespace std;
const long long oo=1e9;
long long ans[3005],s[3005];
int a[3005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	register int n,i,j;
	scanf("%d",&n);
	if(n<=3000){
		for(i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		register int T;
		scanf("%d",&T);
		while(T--){
			register int l,r,len;
			scanf("%d%d",&l,&r);
			for(i=1;i<=n;++i) ans[i]=-oo;
			for(len=l;len<=r;++len){
				for(i=1;i+len-1<=n;++i) 
					for(j=i;j<=i+len-1;++j){
						ans[j]=max(ans[j],s[i+len-1]-s[i-1]);
						//printf("%d:%d %d->%lld\n",j,i,i+len-1,s[i+len-1]-s[i-1]);
					} 
						
			}
			unsigned long long s=0;
			for(i=1;i<=n;++i) s=s^(i*ans[i]);
			printf("%llu\n",s);
		}
	}
	return 0;
}
