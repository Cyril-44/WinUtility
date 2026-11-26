#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> c[8005];
int high[8005],deep[8005];int f[8005],leaf[8005];int ans;
void dfs(int x){
	if(c[x].empty()){
		high[x]=1;
		return;
	}
	for(int i=0;i<c[x].size();i++){
		dfs(c[x][i]);
	}
	int maxn=-1;
	for(int i=0;i<c[x].size();i++){
		maxn=max(maxn,high[c[x][i]]);
	}
	high[x]=maxn+1;
}
void dfs1(int x){
	if(x==1){
		deep[x]=0;
	}else{
		deep[x]=deep[f[x]]+1;
	}
	for(int i=0;i<c[x].size();i++){
		dfs1(c[x][i]);
	}
}
void dfs2(int x){
	if(x==1){
		deep[x]=1;
	}else{
		deep[x]=deep[f[x]]+1;
	}
	for(int i=0;i<c[x].size();i++){
		dfs1(c[x][i]);
	}
}
void dfss(int x){
	ans+=deep[x]-1;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		int m,n;
		for(int i=1;i<=8005;i++){
			c[i].clear();
		}
		f[1]=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>f[i];
			c[f[i]].push_back(i);
		}
		dfs(1);
		dfs1(1);
		dfs2(1);
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=high[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i].empty()){
				dfss(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(high[i]==2){
				ans-=(deep[i]+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
