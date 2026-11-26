#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
struct f{
	LL a,b,s,id;
}e[N],w[N];
bool cmp(f s1,f s2){
	return s1.a<s2.a;
	return s1.s<s2.s;
}
bool cmp1(f s1,f s2){
	return s1.s<s2.s;
	return s1.b>s2.b;
	return s1.a<s2.a;
}
int p[N],s[N];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	LL n,m,a,b,c,ans=0,zx=INT_MAX;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		c=a+b;
		e[i]={a,b,c,i};
		w[i]=e[i];
	}
	sort(e+1,e+n+1,cmp);
	sort(w+1,w+n+1,cmp1);
	zx=w[1].s;a=w[1].a;
	b=w[1].b;
	p[w[1].id]=1;
	/*-for(int i=1;i<=n;i++){
		if(e[i].a<a)s[++cnt]=e[i].a,p[e[i].id]=1,ds+=e[i].a                ;
	}*/
	int t=m/zx;
	m-=zx*t;
	ans+=2*t;
	t=b+m;
	int gs=0;
	for(int i=1;i<=n;i++){
		if(e[i].a<=t&&!p[e[i].id]){
			t-=e[i].a;
			gs++;
		}
		else if(e[i].a>t)break;
	}
	//cout<<ans<<' ';u
	ans=max(ans,ans-1+gs);
	
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<=t;j++){
			if(s[i]<=m+j*zx){
				ans=max(ans,ans-2*j+gs[i]);
				cout<<ans<<' ';
			}
		}
	}*/
	int gs1=0;
	t=m;
	for(int i=1;i<=n;i++){
		if(e[i].a<t){
			gs1++;
			t-=e[i].a;
		}
		else break;
	}
	ans=max(ans,ans+gs1);
	//cout<<ans;
	/*for(int i=1;i<=n;i++){
		if(s[i]<=m+b){
			
		}
	}*/
	cout<<ans<<' ';
	return 0;
}
