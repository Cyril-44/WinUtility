#include<bits/stdc++.h>
#define ll long long 
using namespace std;

inline ll rd(){ll x=0,f=1;char c;c=getchar();while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}while(isdigit(c)){	x=x*10+(c-'0');	c=getchar();}return x*f;}
const int M=1e5+5;
struct T{
	ll x,y,sum;
}e[M];
struct G{
	ll x,y,sum;
}p[M];
ll n,m,ans=0,sum;
bool cmp(T x,T y){
	if(x.sum!=y.sum)
	return x.sum<y.sum;
	else if(x.x!=y.x) return x.x<y.x;
			else return x.y<y.y;
}
bool cmp1(G x,G y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++){
		e[i].x=rd(),e[i].y=rd();
		p[i].x=e[i].x,p[i].y=e[i].y;
		p[i].sum=e[i].sum;
		e[i].sum=e[i].x+e[i].y;
	}
	sort(p+1,p+n+1,cmp1);
	sort(e+1,e+n+1,cmp);
	for(int i=0;i<=n;i++){
		sum+=p[i].x;
		ans=max((m-sum)/e[1].sum*2+i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
