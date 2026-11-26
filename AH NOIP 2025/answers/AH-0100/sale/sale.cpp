#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int mod=998244353;

int c,t,n,m;
int cnt1,cnt2;
int a[MAXN];
int f[MAXN],f1[MAXN],f2[MAXN];
long long ans;

int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}

long long ksm(long long x, int y){
	long long s=1;
	while(y){
		if(y%2==1) s=s*x%mod;
		y/=2;
		x=x*x%mod;
	}
	return s;
}

inline bool cmp(int x, int y){
	return x>y;
}
inline int check(){
	cnt1=cnt2=0;
	for(int i=1; i<=n; i++){
		if(f[i]==1) f1[++cnt1]=a[i];
		else f2[++cnt2]=a[i];
	}
	sort(f1,f1+cnt1+1);
	sort(f2,f2+cnt2+1);
	//for(int i=1; i<=cnt1; i++) cout<<f1[i]<<" "; cout<<endl;
	//for(int i=1; i<=cnt2; i++) cout<<f2[i]<<" "; cout<<endl;
	int c=m,c1=cnt1,c2=cnt2;
	long long sum=0;
	if(c%2==1) sum+=f1[c1--]*1ll,c-=1;
	for(int i=1; i<=c/2; i++){
		if(f1[c1]+f1[c1-1]<f2[c2] && c2>0) sum+=1ll*(f2[c2--]);
		else if(c1>0) sum+=1ll*(f1[c1]+f1[c1-1]),c1-=2;
	}
	
	long long sum1=0;
	c=m,c1=cnt1,c2=cnt2;
	while(c>0){
		if(f1[c1]*2>f2[c2]) sum1+=1ll*f1[c1],c--,c1--;
		else if(f1[c1]*2==f2[c2]){
			if(c>=2) sum1+=1ll*(f2[c2]),c2--,c-=2;
			else sum1+=1ll*(f1[c1]),c1--,c-=1;
		}
		else {
			if(c>=2) sum1+=1ll*(f2[c2]),c2--,c-=2;
			else sum1+=1ll*(f1[c1]),c1--,c-=1;
		}
	}
	if(sum1==sum) return 1;
	return 0;
}
inline void dfs(int k){
	if(k==n+1){
		//for(int i=1; i<=n; i++) cout<<f[i]<<" "; cout<<endl;
		ans+=check();
		return ;
	}
	f[k]=1;
	dfs(k+1);
	f[k]=2;
	dfs(k+1);
	f[k]=0;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%d%d" ,&c,&t);
	while(t--){
		ans=cnt1=cnt2=0;
		for(int i=1; i<=n; i++) a[i]=0,f[i]=f1[i]=f2[i]=0;
		
		n=read(); m=read();
		bool flag=0;
		for(int i=1; i<=n; i++){
			a[i]=read();
			if(a[i]!=a[1]) flag=1;
		}
		sort(a+1,a+n+1);
		
		if(flag==0){
			long long s=ksm(2,n);
			printf("%Illd\n" ,s);
			continue;
		}
		
		if(n<=10){
			dfs(1);
			printf("%Illd\n" ,ans);
		}
		if(m==2){
			long long s=ksm(2,n);
			printf("%Illd\n" ,s);
			continue;		
		}
	}
}
//!noip@Nov29,2025:dream
