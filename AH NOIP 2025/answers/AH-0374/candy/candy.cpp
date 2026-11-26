#include<bits/stdc++.h>
using namespace std;
long long s,n,m,x[100005],y[100005],mn=2147483647,q[100005],f[100005],mx,t;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		mn=min(mn,x[i]+y[i]);
	}
	sort(x+1,x+1+n);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+x[i];
	for(int i=1;i<=n;i++) if(q[i]<=m){
		f[i]=(i+1)/2*mn-q[i];
		mx=max(mx,f[i]);
	}
	if(mx) for(int i=1;i<=n;i++) if(f[i]==mx){
		m-=q[i];
		s=i;
		t=i;
		break;
	}
	s+=m/mn*2;
	m%=mn;
	for(int i=t+1;i<=n;i++){
		if(m<x[i]) break;
		else{
			m-=x[i];
			s++;
		}
	}
	printf("%lld",s);
	return 0;
}
