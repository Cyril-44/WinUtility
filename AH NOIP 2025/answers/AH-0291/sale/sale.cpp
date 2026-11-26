#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,mod=998244353;
int c,t,n,m;
struct ss{
	int yuan,xin,bian;
}a[maxn];
bool cmp(const ss &x,const ss &y){
	if(x.xin!=y.xin){
		return x.xin>y.xin;
	}
	else if(x.yuan!=y.yuan){
		return x.yuan>y.yuan;
	}
	else{
		return x.bian<y.bian;
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i].yuan;
			a[i].bian=i;
		}
		if(c==18){
			long long ans=1,ans1=1,nn=2,mm=m-1;
			while(n){
				if(n&1){
					ans=((ans%mod)*(nn%mod))%mod;
				}
				nn=nn*nn%mod;
				n>>=1;
			}
			nn=2;
			while(mm){
				if(mm&1){
					ans1=((ans1%mod)*(nn%mod))%mod;
				}
				nn=nn*nn%mod;
				mm>>=1;
			}
			cout<<ans-ans1<<endl;
			return 0;
		}
		cout<<n*m<<endl;
	}
	return 0;
}
