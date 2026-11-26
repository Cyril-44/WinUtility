#include<bits/stdc++.h>
using namespace std;
const int N=8009;
int n,m,ans=0,sum=0;
vector<int>gra[N];
int val[N],tong[N];
void dfs(int u){
	tong[val[u]]=1;
	for(unsigned i=0;i<gra[u].size();i++){
		int v=gra[u][i];
		dfs(v);
	}
	return;
}
void init(int u){
	if(u==n+1){
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				tong[j]=0;
			}
			dfs(i);
			for(int j=0;j<=n;j++){
				if(tong[j]==0){
					sum+=j;
					break;
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<n;i++){
		val[u]=i;
		init(u+1);
		val[u]=0;
	}
	return;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<=n+2;i++){
			gra[i].resize(0);
		}
		ans=0;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			gra[x].push_back(i);
		}
		init(1);
		cout<<ans<<endl;
	}
	return 0;
}
//next_permutation