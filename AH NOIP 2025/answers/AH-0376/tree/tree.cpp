#include<bits/stdc++.h>
#define int long long
using namespace std;
int nx[8005],la[8005],pr[8005],pa[8005],a[8005],m,n,t,tot,ans;
void add(int a,int b){
	nx[++tot]=b;
	pr[tot]=la[a];
	la[a]=tot;
}
void dfs(int root){
	if(!la[root]){
		a[root]=0;
		return;
	}
	int mx=-1,s=0,mxi=0,f=0;
	for(int i=la[root];i;i=pr[i]){
		s++;
		if(la[nx[i]]) f=1;
		dfs(nx[i]);
		if(a[nx[i]]>mx){
			mx=a[nx[i]];
			mxi=nx[i];
		}
	}
	a[mxi]++;
	a[root]=s+mx+f;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
		ans=0;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(la,0,sizeof(la));
		tot=0;
		for(int i=2;i<=n;i++){
			cin>>pa[i];
			add(pa[i],i);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<'\n';
    }
    return 0;
}
