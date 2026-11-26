#include <bits/stdc++.h>
using namespace std;

int a[5005];
struct node{
	long long x,y,bh;
}p[5005];
long long dp[10005];
long long mod=998244353;
bool cmp(node x,node y){
	return x.x*y.y!=y.x*x.y?x.x*y.y>y.x*x.y:(x.x!=y.x?x.x>y.x:x.bh<y.bh);
}
long long ksm(long long x,long long y){
	long long sum=1;
	while(y){
		if (y%2) sum=sum*x%mod;
		x=x*x%mod;
		y=y/2;
	}
	return sum;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if (c<=5){
			long long g=0;
			for(int i=0;i<(1<<n);i++){
				for(int j=1;j<=n;j++){
					if ((1<<(j-1))&i) p[j].y=2;
					else p[j].y=1;
					p[j].x=a[j];
					p[j].bh=j;
				}
				for(int i1=0;i1<=m;i1++) dp[i1]=0;
				sort(p+1,p+1+n,cmp);
				long long sum=0;
				int wm=m;
				for(int i1=1;i1<=n;i1++){
					if (wm>=p[i1].y){
						wm-=p[i1].y;
						sum+=p[i1].x;
					}
				}
				for(int i1=1;i1<=n;i1++){
					for(int j=m;j>=p[i1].y;j--){
						dp[j]=max(dp[j],dp[j-p[i1].y]+p[i1].x);
					}
				}
				long long ans=0;
				for(int i1=0;i1<=m;i1++) ans=max(ans,dp[i1]);
				if (ans==sum) g++;
			}	
			cout<<g<<endl;
		}
		if (c==18||c==16){
			cout<<ksm(2,n)%mod<<endl;
		}
	}
	return 0;
}
