#include<bits/stdc++.h>
using namespace std;
vector<int> mapp[8005];
int f[8005],fa[8005],eg[8005],ans=0;
void dfs1(int x){
	int maxx=0,fir=mapp[x][0];
	for(int i=0;i<mapp[x].size();i++){
		if(mapp[x][i]==x)continue;
		if(eg[mapp[x][i]]>maxx){
			fir=mapp[x][i];
			maxx=eg[mapp[x][i]];
		}
	}
	ans+=maxx;
	if(mapp[fir].size()==1)return;
	dfs1(fir);
}
void find(int x){
	while(x!=1){
		x=fa[x];
		eg[x]++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ans=0;
		if(m==n-1){
			cout<<n*(n-1)/2<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		memset(eg,0,sizeof(eg));
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=8005;i++)mapp[i].clear();
		for(int i=2;i<=n;i++){
			int a;
			cin>>a;
			mapp[i].push_back(a);
			mapp[a].push_back(i);
			fa[i]=a;
		}
		for(int i=2;i<=n;i++){
			eg[i]++;
			find(i);
		}//dfs1(1);
		cout<<ans+n<<" ";
	}
	return 0;
}
