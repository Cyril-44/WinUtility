#include<bits/stdc++.h>
using namespace std;
long long T,ans,id,n,m,a[1000005],p[1000005];//c[i][j]:从i选j
struct xxx{
	long long p,x,id;
}k[100005];
bool cmp(xxx a,xxx b){
	if(a.x*2/a.p!=b.x*2/b.p)return a.x*2/a.p>b.x*2/b.p;
	if(a.p!=b.p)return a.p>b.p;
	return a.id<b.id;
}
long long dfs1(long long x,long long l){
	if(x==n+1)return 0;
	if(l>=p[x])return max(dfs1(x+1,l),dfs1(x+1,l-p[x])+a[x]);
	return dfs1(x+1,l);
}
void dfs(long long x){
	if(x==n+1){
		long long l=m,cnt=0;
		for(long long i=1;i<=n;i++){
			k[i].p=p[i];
			k[i].x=a[i];
			k[i].id=i;
		}
		sort(k+1,k+n+1,cmp);
		for(int i=1;i<=n;i++){
			//cout<<p[i]<<' '<<a[i]<<'|';
			if(l>=k[i].p){
				cnt=cnt+k[i].x;
				l=l-k[i].p;
			}
		}
		//cout<<cnt<<' '<<dfs1(1,m)<<'\n';
		if(cnt==dfs1(1,m))ans++;
		return;
	}
	p[x]=1;
	dfs(x+1);
	p[x]=2;
	dfs(x+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	cin>>id>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 10
5 5
10 7 5 5 6
10 7 6 5 5 
48 33 25 24 24
*/
