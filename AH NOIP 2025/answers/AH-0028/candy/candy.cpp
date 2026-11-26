#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j;
long long x,y,minn=1e15;
long long a[100005];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		minn=min(minn,x+y);
		a[i]=x;
	}
	sort(a+1,a+n+1);
	long long ans=0,sum=0;
	for(i=0;i<=n;i++){
		sum+=a[i];
		if(sum>m) break;
		ans=max(ans,i+((m-sum)/minn)*2);
	}
	printf("%lld\n",ans);
	return 0;
}
