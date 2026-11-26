#include<bits/stdc++.h>
using namespace std;
int v[20];
int t;
int n;
int fa[20];
int ans=0;
int w[20];
int s[280000];
void judge(){
	int na=0;
	for(int i=1;i<=n;i++) w[i]=(1<<20)-1;
	for(int i=1;i<=n;i++) w[i]^=1<<v[i];
	for(int i=n;i>1;i--) w[fa[i]]&=w[i];
	for(int i=1;i<=n;i++) na+=s[w[i]&-w[i]];
		// if(v[1]==3&&v[2]==2&&v[3]==0&&v[4]==0&&v[5]==1) cerr<<na<<'\n';
	ans=max(ans,na);
}
void dfs(int k){
	if(k==n+1) judge();
	else{
		for(int i=0;i<n;i++) v[k]=i,dfs(k+1);
	}
}
int main(){
	for(int i=0;i<=15;i++) s[1<<i]=i;
	freopen("tree.in","r",stdin); freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t; while(t--){
		cin>>n; for(int i=2;i<=n;i++) cin>>fa[i];
		ans=0; dfs(1); cout<<ans<<'\n';
	}
	return 0;
}