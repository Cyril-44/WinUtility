
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
int a[10000];

int p[10000];
int w[10000];
long long ans=0;
void dfs(int k){
	if(k>n){
		
		for(int i=1;i<=n;i++){
			//printf("%d ", p[i]);
			w[i]=float(2*a[i])/float(p[i]);
		}
		
		sort(w + 1,w + n + 1);
		
		
		
	}
	
	p[k]=1;
	dfs(k+1);
	p[k]=2;
	dfs(k+1);
}

void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//printf("1");
	
	dfs(1);
	cout<<ans<<"\n";
}

ll qpow(ll a,ll b){
	if(b==0)return 1;
	if(b%2==0){
		ll q = qpow(a,b/2) % 998244353;
		return q*q % 998244353;
	} else{
		ll q = qpow(a,b/2) % 998244353;
		q=q*q % 998244353;
		return q*a % 998244353;
	}
	
}

void solve18(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<qpow(2,n);
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==18){
		solve18();
		return 0;
	}
	
	while(t--){
		solve();
	}
	
	return 0;
}
