#include<bits/stdc++.h>
using namespace std;
long long c,T,t;
long long n,m,mt,ma,anst,ans,anss,dp[10010];
struct node{
	long long x,w,p;
}a[5010],b[5010];
bool cmp1(node t,node s){
	if((double)t.x/t.w==(double)s.x/s.w){
		return t.x>s.x;
	}
	return (double)t.x/t.w>(double)s.x/s.w;
}
void dfs(int k){
	if(k>n){
		memcpy(a,b,sizeof a);
		sort(a+1,a+1+n,cmp1);
		memset(dp,0,sizeof dp);
	//	for(int i=1;i<=n;i++){
	//		cout<<a[i].x<<' '<<a[i].w<<endl;
	//	}
		mt=m,anst=0;
		for(int i=1;i<=n;i++){
			if(mt<=0)break;
			if(mt>=a[i].w){
				anst+=a[i].x;
				mt-=a[i].w;
			}
		}
	//	cout<<anst<<endl;
		anss=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=a[i].w;j--){
				dp[j]=max(dp[j],dp[j-a[i].w]+a[i].x);
				anss=max(dp[j],anss);
			}
		}
	//	cout<<anss<<endl<<endl;
		if(anst==anss)ans++;
		return ;
	}
	b[k].w=1;
	dfs(k+1);
	b[k].w=2;
	dfs(k+1);
	b[k].w=0;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c<=6){
			ans=0,ma=-1;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>b[i].x;
			}
			dfs(1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
