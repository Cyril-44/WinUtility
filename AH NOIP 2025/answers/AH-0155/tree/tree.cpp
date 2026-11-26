#include<bits/stdc++.h>
using namespace std;
int n,m,t,T,a[8010],chans;
vector<int> G[8010];
int check(int x){
	if(G[x].size()==0){
		if(a[x]==0)return 1;
		return 0;
	}
	int mex=0,sz=G[x].size();
	for(int i=0;i<sz;i++){
		int t=check(G[x][i]);
		mex=max(mex,t);
		chans+=t;
	}
	if(mex==a[x])mex++;
	if(x!=1)return mex;
	chans+=mex;
	return chans;
}
int dfs(int x){
	if(x==n+1){
		chans=0;
		return check(1);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		a[x]=i;
		ans=max(ans,dfs(x+1));
	}
	return ans;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=0;i<=8000;i++)G[i].clear();
		for(int i=2;i<=n;i++){
			cin>>t;
			G[t].push_back(i);
		}
		cout<<dfs(1)<<endl;
	}
	return 0;
}
