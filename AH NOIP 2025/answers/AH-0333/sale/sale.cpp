#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[5005],u[5005],dis[10005];
struct o{
	int a,b,c;
}k[5005];
bool cmp(o x,o y){
	if(x.c!=y.c){
		return x.c>y.c;
	}
	return x.a>y.a;
}
void g(){
	for(int i=1;i<=n;i++){
		k[i].a=a[i];
		k[i].b=u[i];
		k[i].c=a[i]/u[i];
	}
	sort(k+1,k+n+1,cmp);
	long long gg=m,s=0;
	for(int i=1;i<=n;i++){
		if(gg>=k[i].b){
			gg-=k[i].b;
			s=s+k[i].a;
		}
		if(gg==0)break;
	}
	memset(dis,0,sizeof(dis));
	int g1;
	long long g2;
	for(int i=1;i<=n;i++){
		g1=k[i].b,g2=k[i].a;
		for(int j=m;j>=g1;j--){
			dis[j]=max(dis[j],dis[j-g1]+g2);
		}
	}
	if(s==dis[m])ans++;
}
void f(int x){
	if(x==n+1){
		g();
		return;
	}
	u[x]=1;
	f(x+1);
	u[x]=2;
	f(x+1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i]*=2;
		}
		f(1);
		printf("%d\n",ans);
	}
	return 0;
}
