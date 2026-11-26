#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int n,m,qu[MAXN];
int gen=1,w;
vector<int> sh[MAXN];
long long s;
bool vis[MAXN][MAXN];
long long js(int rt){
	long long su=0;
	vis[rt][qu[rt]]=1;
	int len=sh[rt].size();
	for(int i=0;i<len;i++){
		int mb=sh[rt][i];
		su+=js(mb);
		for(int j=0;j<=n;j++){
			vis[rt][j]|=vis[mb][j];
		}
	}
	for(int i=0;i<=n;i++){
		if(vis[rt][i]==0){
			su+=i;break;
		}
	}
	return su;
}
void dfs2(int rt,int h){
	m=max(m,h);
	int len=sh[rt].size();
	for(int i=0;i<len;i++){
		dfs2(sh[rt][i],h+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		s=0;
		for(int i=0;i<=n;i++){
			sh[i].clear();
		}
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int o;
			cin>>o;
			sh[o].push_back(i);
		}
		m=0;
		dfs2(gen,0);
		if(m==0){
			cout<<1;
		}
		else if(m==1){
			cout<<n+1;
		}
		else if(m==n-1){
			long long sum=0;
			for(long long i=1;i<=n;i++){
				sum+=i;
			}
			cout<<sum;
		}
		else{
			cout<<2*n-1;
		}
		if(t){
			cout<<'\n';
		}
	}
	return 0;
}
