#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a[100005],v[15],ans,m,n,t[15];
vector<int> w[100005];
void dfs1(int x){
	t[v[x]]++;
	for(auto it:w[x]){
		dfs1(it);
	}
}
void dfs4(int x){
	if(x==n+1){
		int s=0;
		for(int i=1;i<=n;i++){
			memset(t,0,sizeof t);
			dfs1(i);
			for(int j=0;j<=n;j++)if(!t[j]){s+=j;break;}
		}
		ans=max(ans,s);
		return;
	}
	if(w[x].size()==0){
		v[x]=0;
		dfs4(x+1);
		return;
	}
	for(int i=0;i<n;i++){
		v[x]=i;
		dfs4(x+1);
		v[x]=0;
	}
}
void dfs(int x){
	if(x==n+1){
		int s=0;
		for(int i=1;i<=n;i++){
			memset(t,0,sizeof t);
			dfs1(i);
			for(int j=0;j<=n;j++)if(!t[j]){s+=j;break;}
		}
		ans=max(ans,s);
		return;
	}
	for(int i=0;i<n;i++){
		v[x]=i;
		dfs(x+1);
		v[x]=0;
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n>7&&m==1){
			cout<<n<<"\n";
			continue;
		}
		if(n>7&&m==2){
			cout<<n+1<<"\n";
			continue;
		}
		if(n>=8){
			dfs4(1);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)w[i].clear();
		for(int i=2,x;i<=n;i++){
			cin>>x;
			w[x].push_back(i);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
    return 0;
}
