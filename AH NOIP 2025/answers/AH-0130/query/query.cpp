#include<bits/stdc++.h>
using namespace std;
int n,q,L,R,l,r,a[50005],w[50005],v[50005],x[50005],p;
long long b[50005],k[50005];
unsigned tmp,ans;
struct str{
	int l;
	int r;
	long long value;
}u[50005];
bool f[50005];
bool cmp(str x,str y){
	return x.value>y.value;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=1ll*(b[i-1]+a[i]);
	}
	scanf("%d",&q);
	while(q--){
		memset(f,0,sizeof(f));
		scanf("%d%d",&L,&R);
		for(int i=1;i<=n-L+1;i++){
			while(r>0&&a[i]<=a[w[r]]) r--;
			    w[++r]=i;
			while(i-w[l]>R-L) l++;
		}
		u[L].value=b[L];
		u[L].r=L;
		u[L].l=1;
		for(int i=L+1;i<=n;i++){
			u[i].value=b[i]-b[v[i-L]];
			u[i].r=i;
			u[i].l=v[i-L]+1;
			cout<<u[i].value<<" ";
		}
		sort(u+L,u+n+1,cmp);
		for(int i=L;i<=n;i++)
			for(int j=u[i].l;j<=u[i].r;j++)
				if(!f[i]){
					k[i]=u[i].value;
					f[i]=1;
				}
		ans=k[1];
		for(int i=2;i<=n;i++){
			if(k[i]>=0) ans^=(unsigned long long)k[i];
			if(k[i]<0){
				ans^=(unsigned long long)k[i]+1;
			}
		}
		p=0;
		while(ans){
			x[p++]=ans%10;
			ans/=10;
		}
		for(int i=p-1;i>=0;i--)
		    printf("%d",x[i]);
		printf("\n");
	}
}
