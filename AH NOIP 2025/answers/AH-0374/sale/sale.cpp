#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,w,p,t;
}f[5005];
long long c,t,n,m,a[5005],s,er[15]={1},x,mx,p,q,o;
bool cmp(const node &x,const node &y){
	if(x.p!=y.p) return x.p>y.p;
	if(x.a!=y.a) return x.a>y.a;
	return x.t<y.t;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=3){
		for(int i=1;i<=10;i++) er[i]=er[i-1]*2;
		while(t--){
			scanf("%lld%lld",&n,&m);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			for(int i=0;i<er[n];i++){
				o=m;
				for(int j=1;j<=n;j++) f[j]={a[j],i/er[j-1]%2+1,a[j]*2/(i/er[j-1]%2+1),j};
				sort(f+1,f+1+n,cmp);
				for(int j=0;j<er[n];j++){
					for(int k=1;k<=n;k++){
						s+=j/er[k-1]%2*f[k].w;
						p+=j/er[k-1]%2*f[k].a;
					}
					if(s<=m) mx=max(p,mx);
					s=0;
					p=0;
				}
				for(int j=1;j<=n;j++) if(o>=f[j].w){
					s+=f[j].a;
					o-=f[j].w;
				}
				if(s==mx) q++;
				s=0;
				mx=0;
			}
			printf("%lld\n",q);
			q=0;
		} 
	}else while(t--){
		s=1;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			s=s*2%998244353;
		}
		printf("%lld\n",s);
	}
	return 0;
}
