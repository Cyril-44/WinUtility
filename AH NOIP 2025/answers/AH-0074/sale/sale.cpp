#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mol=98244353,N=1e5+5;
int c,t,ans;
int n,m,a[N],b[N];
struct node{
	double yj,w,bb;
	int id;
}aa[N];
bool cmp(node a,node b){
	if(a.w!=b.w)return a.w>b.w;
	return a.yj>b.yj;
}
int dp[N];
void dfs(int cnt){
	if(cnt>n){
		for(int i=1;i<=n;i++){
			aa[i].yj=(double)a[i];
			aa[i].w=(double)a[i]/(double)b[i];
			aa[i].bb=b[i];
			aa[i].id=i;
		}
		sort(aa+1,aa+1+n,cmp);
		int tot=0,res=0;
		for(int i=1;i<=n;i++){
			if(tot+aa[i].bb<=m){
				tot+=aa[i].bb;
				res+=aa[i].yj;
			}
		}
		for(int i=0;i<=m;i++)dp[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=b[i];j--){
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
		if(dp[m]==res){
			ans=(ans+1)%mol;
		}
		return;
	}
	b[cnt]=1;
	dfs(cnt+1);
	b[cnt]=2;
	dfs(cnt+1);
	return;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
