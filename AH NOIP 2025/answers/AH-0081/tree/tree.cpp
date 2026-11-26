/*
这是我写了三个小时写错的T2，如果有人翻到，把我放上去吧。可能要退役了……
衣带渐宽终不悔，为伊消得人憔悴。
我爱编程
rp++
everyone rp++
———v1978DHG
*/
#include<bits/stdc++.h>
using namespace std;
long long T,id,n,m,a[5005],l,r,b,c[5005][5005],ct[5005][5005],me[5005],ans,mod=998244353;//c[i][j]:从i选j
long long cnt(long long a,long long b,long long m){
	//a个0或1，b个1或2，凑m，方案数；
	if(m<0)return 0;
	m=m-a-b;
	long long k=0,r=0;
	if(m>0){
		k=min(b,a-m);
		for(int i=0;i<=k;i++)r=(r+c[b][i]*c[a][i+m]%mod)%mod;
	}
	else{
		k=min(a,b+m);
		for(int i=0;i<=k;i++)r=r+c[a][i]*c[b][i-m];
	}
	return r;
}
bool cmp(long long a,long long b){return a>b;}
long long cn(long long a,long long b,long long m){
	//cout<<a<<' '<<b<<' '<<m<<'\n';
	if(m==a)return 1;
	if(a==0&&b==0)return 0;
	if(a)return cn(a-1,b,m-1)+cn(a-1,b,m-2);
	return cn(a,b-1,m-1)+cn(a,b-1,m);
}
int main(){
	c[0][0]=1;
	for(int i=1;i<=5000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	me[0]=1;
	for(int i=1;i<=5000;i++)me[i]=me[i-1]*2;
	cin>>id>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1,cmp);
		l=0;
		for(int i=2;i<=n;i++){
			while(a[l+1]>=a[i]*2)l++;
			r=l;
			for(int j=i+1;j<=n+1;j++){
				while(a[r+1]>a[j]+a[i]&&r<i-1)r++;
				ans=(ans+(cnt(l,i-l-1,m-2)-cnt(l,i-r-1,m-2-(r-l))+mod)%mod*me[max(0ll,n-j)]%mod)%mod;
				cout<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<cnt(l,i-l-1,m-2)<<' '<<cnt(l,i-r-1,m-2-(r-l))<<' '<<ans<<'\n';
			}
		}
		cout<<(me[n]-ans+mod)%mod<<'\n';
	}
}
