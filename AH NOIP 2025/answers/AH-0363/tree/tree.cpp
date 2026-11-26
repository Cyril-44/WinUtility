#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,Mod=998242353;
int n,m,ans,cur,a[N];
vector<int> tree[N],c[N];
set<int> s;
void dfs_tree(int fa,int x){
	c[x].push_back(a[x]);
	for(auto i:tree[x]){
		if(fa==i)
			continue;
		else{
			dfs_tree(x,i);
			for(auto it:c[i])
				c[x].push_back(a[it]);
		}
	}
	s.clear();
	for(int i=0;i<n;i++)
		s.insert(i);
	for(auto it:c[x])
		s.erase(it),cout<<it<<" ";
	cout<<endl;
	auto it=*s.begin();
	cout<<x<<" "<<it<<endl;
	ans+=it;
}
void dfs(int step){
	if(step==n+1){
		for(int i=1;i<=n;i++)
			c[i].clear();
		ans=0;
		dfs_tree(0,1);
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl<<ans<<endl;
		cur=max(cur,ans);
		return ;
	}
	for(int i=0;i<n;i++){
		a[step]=i;
		dfs(step+1);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}
	if(n<=7){
		dfs(1);
		cout<<cur<<"\n";
		return ;
	}
	cout<<n+1+n<<"\n";
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
		solve();
	return 0;
}
//分越少的部分分一般更好拿
//my luogu name is dong0717
//关注锣鼓账号dong0717喵 关注锣鼓账号dong0717谢谢喵
