#include<bits/stdc++.h>
#define int long long
using namespace std;
struct o{
	int v,h,id;
	int rc,lb;
	int dad;
}a[1000005];
int t,h,id;
int n,m,ans;
void dfs(int x,int q){
	a[x].h=q;
	h=max(h,q);
	if(a[x].rc==0){
		a[x].v=a[a[x].dad].id;
		if(a[a[x].dad].id==0)ans++;
		a[a[x].dad].id++;
		return;
	}
	int s=0;
	for(int i=a[x].rc;i>0;i=a[i].lb)dfs(i,q+1),s=max(s,a[i].v);
	a[x].v=s+1;
	ans+=a[x].v+1;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n>>m,ans=0;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			a[i].dad=x;
			a[i].lb=a[x].rc;
			a[x].rc=i;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
//!noip@Nov29,2025:dream
/*
1
8 6
1 2 3 4 2 3 4


*/
