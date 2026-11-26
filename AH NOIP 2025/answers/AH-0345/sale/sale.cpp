#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=10800;
using ll=long long;
int c,t,n,m,ans;
struct node{
	int a,p,bian;
}ap[N],tmp[N];
ll f[M];
ll maxx(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=ap[i].p;j--)f[j]=max(f[j],f[j-ap[i].p]+ap[i].a);
	}
	return f[m];
}
bool cmp(node x,node y){
	if(x.a*y.p==y.a*x.p){
		if(x.a==y.a&&x.p==y.p)return x.bian<y.bian;
		return x.a>y.a;
	}else{
		return x.a*y.p>y.a*x.p;
	}
}
ll com(){
	for(int i=1;i<=n;i++)tmp[i]=ap[i];
	sort(tmp+1,tmp+n+1,cmp);
	ll les=m,ans=0;
	for(int i=1;i<=n;i++){
		if(les>=tmp[i].p){
			ans+=tmp[i].a;
			les-=tmp[i].p;
		}
	}
	return ans;
}
void dfs(int now){
	if(now==n+1){
		//for(int i=1;i<=n;i++)cout<<ap[i].a<<" "<<ap[i].p<<"   ";
		//cout<<"\n"<<maxx()<<" "<<com()<<"\n";
		if(maxx()==com())ans=(ans+1)%998244353;
		return;
	}
	ap[now].p=1;
	dfs(now+1);
	ap[now].p=2;
	dfs(now+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&ap[i].a);
		for(int i=1;i<=n;i++)ap[i].bian=i;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
