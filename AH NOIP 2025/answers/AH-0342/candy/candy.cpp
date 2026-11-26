#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
	int id;
}c[100005];
int n;
long long m;
void init(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&c[i].a,&c[i].b);
		c[i].id=i;
	}
	return;
}
bool cmp1(node x,node y){
	return x.a+x.b<y.a+y.b;
}
bool cmp2(node x,node y){
	return x.a<y.a;
}
long long ans=0;
long long tt[200005];
int mm=0;
void work(){
	sort(c+1,c+1+n,cmp1);
	long long k=c[1].a+c[1].b;
	sort(c+1,c+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(c[i].a>=k)break;
		tt[++mm]=c[i].a;
	}
	long long sum=0,ns,tmp;
	for(int i=1;i<=mm;i++){
		sum+=tt[i];
		ns=i;
		if(sum>m)break;
		tmp=m-sum;
		ns+=2*(tmp/k);
		ans=max(ans,ns);
	}
	ans=max(ans,2*(m/k));
	printf("%lld",ans);
	return;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int t=1;
	//~ scanf("%d",&t);
	while(t--){
		init();
		work();
	}
	return 0;
}
