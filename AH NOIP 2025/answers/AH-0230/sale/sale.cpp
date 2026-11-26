#include<bits/stdc++.h>
using namespace std;
const int n1=1e4+5;
const int p=998244353;
struct candy{
	int a,w,id;
	double p;
}ca[n1];
int n,m,c,t,ans,f[3][n1],mmp,tt;
int ksm(int x,int k){
	int s=1;
	while(k){
		if(k&1) s=s*x%p;
		k>>=1;
		x=x*x%p;
	}
	s=s%p;
	return s;
}
bool cmp(candy a,candy b){
	if(a.p==b.p){
		if(a.a==b.a) return a.id<b.id;
		return a.a>b.a;
	}
	return a.p>b.p;
}
void dfs1(int v,int w,int i){
	if(v<0) return;
	if(i==n+1) mmp=max(mmp,w);
	if(i>n+1)return;
	dfs1(v,w,i+1);
	dfs1(v-ca[i].w,w+ca[i].a,i+1);
}
void dfs(int ip){
	if(ip!=n+1){
		ca[ip].w=1;dfs(ip+1);
		ca[ip].w=2;dfs(ip+2);
		return;
	}
	sort(ca+1,ca+1+n,cmp);
	int mp=0,mm=m,id=1;
	while(m && id<=n){
		if(m>=ca[id].w){
			mp+=ca[id].a;
			m-=ca[id].w;
		}
	}
	dfs1(mm,0,1);
	if(mp==mmp){
		ans++;
		ans=ans%p;
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&ca[i].a);
			ca[i].id=i;
		}
		for(int i=2;i<=n;i++) if(ca[i].a==ca[i-1].a) tt++;
		if(tt==n-1){
			ans=ksm(2,n);
			printf("%d\n",ans);
			continue;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
