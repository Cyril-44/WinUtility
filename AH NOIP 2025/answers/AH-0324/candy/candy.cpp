#include<bits/stdc++.h>
using namespace std;
long long x[100001],y[100001];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	long long mxy=x[1]+y[1];
	for(int i=2;i<=n;i++)mxy=min(mxy,x[i]+y[i]);
	sort(x+1,x+n+1);
	long long qzh=0,ans=m/mxy*2;
	for(int i=1;i<=n;i++){
		qzh+=x[i];
		if(qzh>m)break;
		ans=max(ans,i+(m-qzh)/mxy*2);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
