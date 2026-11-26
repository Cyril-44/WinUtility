#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,cnt;
long long pw[100001];
long long a[100001],c[101],dp[101];
struct node{
	double x;
	long long y,z;
}s[101];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	return a.y>b.y;
}
void dfs(int step){
	if(step>n){
		for(int i=1;i<=n;i++){
			s[i].x=1.0*a[i]/c[i];
			s[i].y=a[i];
			s[i].z=c[i];
		}
		sort(s+1,s+n+1,cmp);
		int tmp=m;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(tmp>=s[i].z){
				ans+=s[i].y;
				tmp-=s[i].z;
			} 
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=m;j>=s[i].z;j--){
				dp[j]=max(dp[j],dp[j-s[i].z]+s[i].y);
			}
		}
		if(ans==dp[m]) cnt++;
		return ;
	}
	c[step]=1;
	dfs(step+1);
	c[step]=2;
	dfs(step+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==16 || c==18){
			long long ans=1;
			for(int i=1;i<=n;i++) ans=ans*2%mod;
			cout<<ans<<"\n";
		}
		if(c==17){
			sort(a+1,a+n+1);
			long long ans=1;
			for(int i=1;i<=n;i++) ans=ans*2%mod;
			if(a[2]<a[1]*2 && a[1]!=a[2]) ans--;
			cout<<ans<<"\n";
		}
		if(c<=5){
			cnt=0;
			dfs(1);
			cout<<cnt<<"\n";
		}
		if((c>=7 && c<=9) || (c==14 || c==15)){
			sort(a+1,a+n+1);
			pw[0]=1;
			pw[1]=2;
			for(int i=2;i<=n;i++) pw[i]=pw[i-1]*2%mod;
			int j=upper_bound(a+1,a+n+1,a[n]/2)-a;
			long long ans=0;
			ans+=pw[n-1]+pw[j-1];
			for(int i=1;i<n;i++) ans=ans*2%mod;
			for(int i=1;i<n;i++){
				int j=lower_bound(a+1,a+n,a[n]-a[i])-a;
				ans+=n-j;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
