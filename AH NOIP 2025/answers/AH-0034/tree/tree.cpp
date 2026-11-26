#include<bits/stdc++.h>
#define N 8005
using namespace std;
int n,m,p[N],cnt[N],c[N][N],k[N],w[N],f[N],ans=0;
int find(int x){
	for(int i=0;i<=n;i++) f[i]=0;
	stack<int> s;
	s.push(x);
	int maxn=0;
	while(!s.empty()){
		int u=s.top();s.pop();
		maxn=max(maxn,k[u]);
		for(int i=1;i<=cnt[u];i++){
			f[k[c[u][i]]]++;
			s.push(c[u][i]);
		}
	}
	k[x]=maxn+1;f[k[x]]++;
	for(int i=0;i<=n;i++)
	if(f[i]==0) return i;
	return 0;
}
void check(){
	int sum=0;
	for(int i=1;i<=n;i++) k[i]=w[i];
	for(int i=n;i>=1;i--){
		if(cnt[i]==0)
			sum+=(k[i]==0);
		if(cnt[i]!=0)
			sum+=find(i);
	}
	ans=max(ans,sum);
}
void dfs(int x){
	if(x>n) {check();return;}
	for(;x<=n;x++)
	if(cnt[x]==0) break;
	for(int i=0;i<n;i++){
		w[x]=i;dfs(x+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) w[i]=0;
		for(int abc,def,i=2;i<=n;i++){
			cin>>p[i];
			cnt[p[i]]++;
			abc=p[i],def=cnt[p[i]];
			c[abc][def]=i;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
