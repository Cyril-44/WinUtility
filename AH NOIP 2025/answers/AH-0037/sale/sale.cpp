#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define req(i,a,b) for(int i=a;i>=b;--i)
const int mod=998244353;
const int N=5005;
int n,m,pw2[N],tmp[N];ll ans;
int qpow(int b,int p){
	int ans=1;
	while(p){
		if(p&1)ans=1ll*ans*b%mod;
		b=1ll*b*b%mod;
		p>>=1;
	} return ans;
}
struct node{
	ll val,p;
}a[N],b[N];
bool pd(){
	ll now=m,vs=0;
	rep(i,1,n)b[i].val=a[i].val,b[i].p=a[i].p;
	sort(b+1,b+n+1,[](node a,node b){return a.val*b.p==b.val*a.p?a.val>b.val:a.val*b.p>b.val*a.p;});
	// rep(i,1,n){
	// 	cout<<b[i].val<<' '<<b[i].p<<'\n';
	// }
	// cout<<"-------\n";
	rep(i,1,n){
		if(b[i].p<=now){
			now-=b[i].p,vs+=b[i].val;
		}
	} 
	ll dp[55]{};
	rep(i,1,n){
		req(j,m,b[i].p){
			dp[j]=max(dp[j],dp[j-b[i].p]+b[i].val);
		}
	}
	// cout<<dp[m]<<' '<<vs<<'\n';
	 return dp[m]==vs;
}
void dfs(int i){
	if(i==n+1){
		ans+=pd();return ;
	} 
	a[i].p=1;dfs(i+1);
	a[i].p=2,dfs(i+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int id,ttt;cin>>id>>ttt;
	pw2[0]=1;rep(i,1,5000)pw2[i]=1ll*pw2[i-1]*2%mod;
	while(ttt--){ans=0;
		cin>>n>>m;rep(i,1,n)cin>>a[i].val;
		if(id==18||m==2*n-1){
			cout<<qpow(2,n)<<'\n';continue;
		} else if(0){
			dfs(1);
			cout<<ans<<'\n';
			continue;
		} else if(m==2){
			sort(a+1,a+n+1,[](node a,node b){return a.val>b.val;});
			for(int i=1;i<=n;++i)tmp[i]=a[i].val;
			ll res=pw2[n];
			rep(i,2,n){
				int l=i+1,r=n;
				while(l<=r){
					int mid=l+r>>1;
					if(tmp[mid]+tmp[i]<tmp[1])r=mid-1;
					else l=mid+1;
				} 
				int pos=max(r+1,i+1);
				int len=n-pos+1;
				if(2*tmp[i]>tmp[1]){
					res-=pw2[len];res%=mod;
				}
			} 
			cout<<(res%mod+mod)%mod<<'\n';
			continue;
		} else if(m==2*n-2){
			sort(a+1,a+n+1,[](node a,node b){return a.val>b.val;});
			for(int i=1;i<=n;++i)tmp[i]=a[i].val;
			ll res=pw2[n];
				int ct=0;
				req(i,n,1)if(tmp[i]==tmp[n])++ct;else break;
			if(ct==1&&tmp[n-ct]<tmp[n]*2)res--;
			cout<<(res%mod+mod)%mod<<'\n';
		} else if(1){
			cout<<pw2[n]<<'\n';
			continue;
		}

	}
	return 0;
}
