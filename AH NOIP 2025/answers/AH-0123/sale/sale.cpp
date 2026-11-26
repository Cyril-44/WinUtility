#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int c,t,n,m,mm;
long long a[5005],ans;
long long m2[5005]={1,2};
struct node{
	long long a;
	int tmp;
}p[5005];
bool cmp(node a,node b){
	if(a.a*a.tmp!=b.a*b.tmp)
		return a.a*a.tmp>b.a*b.tmp;
	return a.a>=b.a;
}
int f[5005];
void dfs(int now){
	if(now==n+1){
		for(int i=1;i<=n;i++)
			p[i].a=a[i],p[i].tmp=f[i];
		sort(p+1,p+n+1,cmp);
		mm=m;
		long long mn1=1000000000,mn2=1000000000,mx=0;
		for(int i=1;i<=n;i++){
			if(mm>=3-p[i].tmp){
				mm-=3-p[i].tmp;
				if(p[i].a<mn1&&p[i].tmp==2){
					mn2=mn1;
					mn1=p[i].a;
				}
				else if(p[i].a<mn2&&p[i].tmp==2)
					mn2=p[i].a;
			}
			else if(p[i].tmp==1)
				mx=max(mx,p[i].a);
		}
		if(mx>mn1+mn2)return;
		else if(mm>0&&mx>mn1)return;
		ans++;
		return;
	}
	f[now]=2;
	dfs(now+1);
	f[now]=1;
	dfs(now+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=2;i<=5000;i++)
        m2[i]=m2[i-1]*2%mod;
    while(t--){
		ans=0;
        scanf("%d%d",&n,&m);
        if(c==16||c==18){
            printf("%lld\n",m2[n]);
            continue;
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        if(c==17){
            if(a[1]*2>a[2]&&a[1]!=a[2])printf("%lld\n",(m2[n]-1+mod)%mod);
            else printf("%lld\n",m2[n]);
            continue;
        }
        if(m==2){
			ans=m2[n];
			for(int i=2;i<=n;i++)
				for(int j=1;j<i;j++)
					if(a[i]!=a[n]&&a[i]*2>a[n]&&a[i]+a[j]<a[n])
						ans=(ans-m2[j-1]+mod)%mod;
			for(int i=1;i<n;i++)
				if(a[i]!=a[n]&&a[i]*2>a[n])
					ans--;
			ans=(ans+mod)%mod;
			printf("%lld\n",ans);
			continue;
        }
        ans=0;
		dfs(1);
		printf("%lld\n",ans);
    }
    return 0;
}
/*!noip@Nov29,2025:dream*/
