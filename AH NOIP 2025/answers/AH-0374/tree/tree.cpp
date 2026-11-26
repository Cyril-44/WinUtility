#include<bits/stdc++.h>
using namespace std;
long long t,n,m,p[8005],f,mx,s;
unordered_map<long long,unordered_map<long long,long long>> mp;
void dfs(long long r){
	if(r==n+1){
		for(int i=1;i<=n;i++) for(int j=0;j<n;j++) if(!mp[i][j]){
			s+=j;
			break;
		}
		mx=max(mx,s);
		s=0;
		return;
	}
	for(int i=0;i<n;i++){
		f=r;
		while(f){
			mp[f][i]++;
			f=p[f];
		}
		dfs(r+1);
		f=r;
		while(f){
			mp[f][i]--;
			f=p[f];
		}
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=2;i<=n;i++) scanf("%lld",&p[i]);
		dfs(1);
		printf("%lld\n",mx);
		mx=0;
	}
	return 0;
}
