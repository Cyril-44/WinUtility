#include<bits/stdc++.h>
using namespace std;
vector<int>v[1001];
int num[1001],c[1001],fa[1001],s[1001],n,m,mx;
int dsf(int root){
	if(s[root]==0) return num[root];
	for(int i=0;i<s[root];i++){
		num[root]|=dsf(v[root][i]);
	}
	return num[root];
}
int f(int x){
	int cnt=0;
	while(x){
		if(x%2==0) return cnt;
		cnt++;
		x/=2;
	}
	return cnt;
}
void dfs(int step){
	if(step>n){
		int ans=0;
		for(int i=1;i<=n;i++) num[i]=1<<c[i];
		dsf(1);
		for(int i=1;i<=n;i++) ans+=f(num[i]);
		mx=max(mx,ans);
		return ;
	}
	for(int i=0;i<n;i++){
		c[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mx=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++) cin>>fa[i];
		for(int i=2;i<=n;i++){
			v[fa[i]].push_back(i);
			s[fa[i]]++;
		}
		dfs(1);
		cout<<mx<<"\n";
	}
	return 0;
}
