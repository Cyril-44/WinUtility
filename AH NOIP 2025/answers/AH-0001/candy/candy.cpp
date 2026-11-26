#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100005;
int n;
ll m,cnt,ans,sum[Maxn];
struct node{
	int x,y;
	bool operator<(const node &u)const{return x+y<u.x+u.y;}
}e[Maxn];
bool cmp(const node &u,const node &v){return u.x<v.x;}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d%d",&e[i].x,&e[i].y);
	sort(e+1,e+1+n);sort(e+2,e+1+n,cmp);
	cnt=m/(e[1].x+e[1].y)*2;
	if ((m-(e[1].x+e[1].y)*cnt/2)>=e[1].x) ++cnt;
	ans=cnt;
	for(int i=1;i<n;++i) sum[i]=sum[i-1]+e[i+1].x;
	for(int i=1;i<n;++i){
		ll cntp=cnt-i,lef=m;
		if (cntp&1) lef-=cntp/2*(e[1].x+e[1].y)+e[1].x;
		else lef-=cntp/2*(e[1].x+e[1].y);
		cntp+=upper_bound(sum+1,sum+n,lef)-sum-1;
		ans=max(ans,cntp);
	}
	printf("%lld\n",ans);
	return 0;
}
