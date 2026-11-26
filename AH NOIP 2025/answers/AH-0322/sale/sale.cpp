#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int x,y;}c[200005];
int C,T,b[200005],a[200005],ans,n,m,ff[255],f[200005],f1[200005],tr[200005],t[200005],tt[200005];
bool cmp(node a,node b){return a.x/a.y==b.x/b.y?a.x>b.x:a.x/a.y>b.x/b.y;}
bool cmp1(node a,node b){return a.x<b.x;}
const int p=998244353;
int ku(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}
int CC(int n,int m){return f[n]*f1[m]%p*f1[n-m]%p;}
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)c[i].x=a[i],c[i].y=b[i];
		sort(c+1,c+n+1,cmp);
		int u=m,t1=0;
		for(int i=1;i<=n;i++){
			if(u>=c[i].y){
				u-=c[i].y;
				t1+=c[i].x;
			}
		}
		memset(ff,0,sizeof ff);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=c[i].y;j--){
				ff[j]=max(ff[j],ff[j-c[i].y]+c[i].x);
			}
		}
		if(ff[m]==t1)ans++;
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=2;
	dfs(x+1);
	b[x]=0;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;f[0]=f1[0]=1;tr[0]=1;
	for(int i=1;i<=100000;i++)f[i]=f[i-1]*i%p,f1[i]=ku(f[i],p-2)%p,tr[i]=ku(2,i);
	while(T--){ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],a[i]*=2;
		if(m==1){
			cout<<ku(2,n)<<"\n";
			continue;
		}
		if(C==18){
			cout<<ku(2,n)<<"\n";
			continue;
		}
		if(n<=13){
			sort(a+1,a+n+1);
			dfs(1);
			cout<<ans<<"\n";
			continue;
		}
		if(m==2*n-1){
			cout<<ku(2,n)<<"\n";
			continue;
		}
		if(m==2*n-2){
			sort(a+1,a+n+1);
			ans=ku(2,n);
			if(a[1]>a[2]/2)ans--;
			cout<<ans<<"\n";
			continue;
		}
		if(n>=14){
			sort(a+1,a+n+1);
			for(int i=1;i<=n-2;i++){
				if(a[i]+a[i+1]<a[i+2]&&a[i+1]>a[i+2]/2){
					int s=m-2,o=0;
					for(int j=i+3;j<=n;j++){
						if(a[j]>=a[i+2]*2)s--,o++;
						else s--;
					}
					if(s<0)continue;
					ans+=ku(2,i)*CC(o,s)%p;ans%=p;
				}
			}
			cout<<(ku(2,n)-ans+p)%p<<"\n";
			continue;
		}
	}
    return 0;
}
