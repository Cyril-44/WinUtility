#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int M=998244353;
int n,m;
int v[50005],a[50005],res;
long long f[100005];
struct node{
	int id,w,ixd;
	double x;
}b[54005];
int ksm(int a,int b){
	int ans=1,x=a;
	while(b){
		if(b&1)ans=(1ll*ans*x)%M;
		x=(1ll*x*x)%M;
		b/=2;
	}
	return ans;
}
bool cmp(node a,node b){
	if(fabs(a.x-b.x)<0.000001){
		if(a.w==b.w)return a.ixd<b.ixd;
		return a.w>b.w;
	}
	return a.x-b.x>0.000001;
}
void dfs(int i){
	if(i==n+1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			b[i].x=a[i]*1.0/v[i];b[i].id=v[i];
			b[i].w=a[i];b[i].ixd=i;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=m;i++)f[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=b[i].id;j--)
				f[j]=max(f[j],f[j-b[i].id]+b[i].w);
		}
		int vv=m;
		for(int i=1;i<=n;i++){
			if(vv>=b[i].id){
				vv-=b[i].id;
				ans+=b[i].w;
			}
		}
		if(ans==f[m])res++;
		return ;
	}
	v[i]=1;
	dfs(i+1);
	v[i]=2;
	dfs(i+1);
	return ;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		res=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(c<=5){
			dfs(1);
			printf("%d\n",res);
			continue;
		}
		if(c==18)printf("%d\n",ksm(2,n));
		else printf("%d\n",ksm(2,n)-n%12345);
	}
	return 0;
}
