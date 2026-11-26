#include<bits/stdc++.h>//6有误
using namespace std;
const int N=1e5+5;
struct node{
	int v,id,wz;
}a[N<<1];
int x[N],y[N];
inline bool cmp(node x,node y){
	if(x.v*y.id!=y.v*x.id) return x.v*y.id<y.v*x.id;
	return x.id<y.id;
}
inline bool cmp1(node x,node y){
	if(x.id!=y.id) return x.id<y.id;
	return x.v<y.v;
}
int tot=0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	register long long n,m,ans=0,exm,ans1;
	register int i,F=1;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		a[++tot]=(node){x[i],1,i};
		a[++tot]=(node){x[i]+y[i],2,i};
	}
	sort(a+1,a+1+tot,cmp);
	i=1;
	while(a[i].id==1&&m>=a[i].v){
		++ans;
		m-=a[i].v;
		a[i].v=y[a[i].wz];
		++i;
	}
	if(m<a[i].v) F=0;
	ans+=(m/a[i].v)*2,m=m%a[i].v;
	ans1=ans-2,exm=m+a[i].v;
	sort(a+1,a+1+tot,cmp1);
	i=1;
	while(i<=tot){
		if(a[i].v>m) break;
		m-=a[i].v,ans+=a[i].id;
		++i;
	}
	i=1;
	while(i<=tot){
		if(a[i].v>exm) break;
		exm-=a[i].v,ans1+=a[i].id;
		++i;
	}
	if(!F) ans1=-1;
	printf("%lld\n",max(ans,ans1));
	return 0;
}
//!noip@Nov29,2025:dream
