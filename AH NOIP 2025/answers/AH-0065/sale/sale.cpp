#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],d[N],e[N];
int C,T;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
long long g1(){
	int cl=0,dl=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1) c[++cl]=a[i];
		else d[++dl]=a[i];
	}
	long long res=0;
	int mm=m;
	int now=0;
	c[cl+1]=0;
	if(m&1){
		if(cl>0) res+=c[1];
		m--;
		for(int i=2;i<=cl;i+=2) e[++now]=c[i]+c[i+1];
	}
	else{
		for(int i=1;i<=cl;i+=2) e[++now]=c[i]+c[i+1];
	}
	for(int i=1;i<=dl;i++){
		e[++now]=d[i];
	}
	sort(e+1,e+now+1,cmp);
	m/=2;
	for(int i=1;i<=m&&i<=now;i++) res+=e[i];
	m=mm;
	return res;
}
bool cmp2(int x,int y){
	double w1=1.0*a[x]/b[x],w2=1.0*a[y]/b[y];
	if(w1!=w2) return w1>w2;
	return a[x]>a[y];
}
long long g2(){
	int mm=m;
	for(int i=1;i<=n;i++){
		c[i]=i;
	}
	sort(c+1,c+n+1,cmp2);
	long long res=0;
	for(int i=1;i<=n;i++){
		if(m>=b[c[i]]){
			m-=b[c[i]];
			res+=a[c[i]];
		}
	}
	m=mm;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	if(C==18){
		while(T--){
			cin>>n>>m;
			int res=1,mod=998244353;
			for(int i=1;i<=n;i++) cin>>a[i],res*=2,res%=mod;
			cout<<res<<'\n';
		}
		return 0;
	}
	while(T--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,cmp);
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j)) b[j+1]=1;
				else b[j+1]=2;
			}
			if(g1()==g2()) ++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
