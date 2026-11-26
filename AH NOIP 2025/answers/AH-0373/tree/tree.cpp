#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
int n,m,id,ans,s[100010],son[100010],head[100010];
struct edge{
	int v,next;
}e[100010];
void add(int u,int v){
	e[++id] = edge{v,head[u]};
	head[u] = id;
}
void dfs(int u){
	int max_id = 0;
	s[u] = 1;
	for(int i = head[u];i;i = e[i].next){
		dfs(e[i].v);
		s[u] += s[e[i].v];
		if(s[max_id] < s[e[i].v]) max_id = e[i].v;
	}
	son[u] = max_id;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i,t,fa;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans = id = 0;
		memset(head,0,sizeof(head));
		rep(i,2,n,1){
			cin>>fa;
			add(fa,i);
		}
		dfs(1);
		fa = 1;
		while(fa){
			ans += s[fa];
			fa = son[fa];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
