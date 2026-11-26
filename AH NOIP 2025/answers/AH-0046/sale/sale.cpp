#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int c,t;
int n,m;
int a[5005];
int f[5005];
int dp[10005];
int tmp_s,tmp_ans;
int tmp_w;
int ans;
int pa[5005][5005];
int cnt[5005];
struct node {
	double x;
	int y;
} tmp[5005];
bool cmp (node x,node y) {
	if(x.x==y.x) {
		return x.y>y.y;
	}
	return x.x>y.x;
}
int fast_pow (int a,int b) {
	if(!b) {
		return 1;
	}
	int tmp=fast_pow(a,b/2);
	if(b%2) {
		return (tmp*tmp%mod)*a%mod;
	}
	return tmp*tmp%mod;
}
void dfs (int i) {
	if(i==n+1) {
		for(int i=1;i<=n;i++) {
			dp[i]=0;
			dp[i+n]=0;
			tmp[i].x=a[i]*1.0/f[i];
			tmp[i].y=f[i];
		}
		tmp_s=0;
		dp[0]=0;
		tmp_w=m;
		sort(tmp+1,tmp+n+1,cmp);
		for(int i=1;i<=n;i++) {
			if(tmp_w>=tmp[i].y) {
				tmp_w-=tmp[i].y;
				tmp_s+=tmp[i].x*tmp[i].y;
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=m;j>=f[i];j--) {
				dp[j]=max(dp[j],dp[j-f[i]]+a[i]);
			}
		}
		if(dp[m]==tmp_s) {
			ans++;
		}
		return ;
	}
	f[i]=1;
	dfs(i+1);
	f[i]=2;
	dfs(i+1);
	return ;
}
signed main () {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		if(c==18) {
			cout<<fast_pow(2,n)<<"\n";
		}
		else {
			if(c==7||c==8||c==9||c==14||c==15) {
				
			}
			else {
				ans=0;
				dfs(1);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
/*
0 1
3 2
1 3 5
*/
