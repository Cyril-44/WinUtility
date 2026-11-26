#include <bits/stdc++.h>
using namespace std;
struct candy{
	int a,w,id;
	double p;
}a[100];
int n,m;
bool cmp(const candy a,const candy b){
	if(a.p!=b.p)	return a.p>b.p;
	else if(a.a!=b.a)	return a.a>b.a;
	else
	{
		return a.id<b.id;
	}
}
int ans=0,dp[1100];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a;
		}
		int maxn=0;
		for(int i=1;i<=(1<<n)-1;i++){
			dp[i]=0;
			for(int j=1;j<=n;j++){
				if(i>>j){
					a[j].w=1;
					a[j].p=a[j].a/a[j].w*1.0;
				}
				else
				{
					a[j].w=2;
					a[j].p=a[j].a/a[j].w*1.0;
				}
			}
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n;j++){
				if(m>=a[j].w){
					m-=a[j].w;
					dp[i]+=a[j].a;
				}
			}
			maxn=max(maxn,dp[i]);
		}
		for(int i=1;i<=(1<<n)-1;i++){
			if(dp[i]==maxn)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
