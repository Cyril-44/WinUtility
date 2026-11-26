#include<bits/stdc++.h>
using namespace std;
struct awa{
	int cc,mm,a,g;
}b[100005];
const int mod=998244353;
int c,T;
int n,m,a[100005];
long long dp[25];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==18){
			int ans18=0;
			for(int i=1;i<=n;i++)ans18=(ans18*2)%mod;
			cout<<ans18<<endl;
		}
		if(c>=1&&c<=5){
			int ans1_5=0;
			for(int i=0;i<(1<<n);i++){
				int ti=i,m1=m;
				long long sum=0;
				memset(dp,0,sizeof(dp));
				for(int i=1;i<=n;i++){
					int yu=(ti&1)+1;
					b[i].a=a[i];
					b[i].g=yu;
					b[i].cc=b[i].a/yu,b[i].mm=b[i].a%yu;
					ti>>=1;
				}
				for(int i=1;i<=n;i++){
					for(int j=m;j>=b[i].g;j--)dp[j]=max(dp[j],dp[j-b[i].g]+b[i].a);
				}
				sort(b+1,b+n+1,[](awa p,awa q){
					return p.cc>q.cc||(p.cc==q.cc&&p.mm>q.mm)||(p.cc==q.cc&&p.mm==q.mm&&p.a>q.a);
				});
				for(int i=1;i<=n;i++){
					if(m1>=b[i].g)m1-=b[i].g,sum+=b[i].a;
				}
				if(sum==dp[m])ans1_5++;
			}
			cout<<ans1_5%mod<<endl;
		}
	}
	return 0;
}
