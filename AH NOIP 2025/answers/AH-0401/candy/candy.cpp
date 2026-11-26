#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,id;
	bool operator < (const node &rhs) const {
		return x<rhs.x;
	}
}a[100010];
long long n,m,minx=1e18,miny=1e18,cnt,y,h,maxn,s[100010];
vector<long long> v;
bool f=1;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		a[i].id=i;
		if((minx+miny>a[i].x+a[i].y)||(minx+miny==a[i].x+a[i].y&&minx>a[i].x))
			minx=a[i].x,miny=a[i].y;
	}
	sort(a+1,a+n+1);
	if(minx==miny&&minx==a[1].x){
		printf("%lld",m/minx);
		return 0;
	}
	for(long long i=1;i<=n;i++) h+=a[i].x;
	cnt=m/(minx+miny)*2;
	y=m%(minx+miny);
	if(y>=minx) cnt++,y-=minx,f=0;
	while(y<=h&&y<=m){
		v.push_back(y);
		if(f) y+=miny;
		else y+=minx;
		f=!f;
	}
	for(long long i=1;i<=n;i++){
		if(v[v.size()-1]<a[i].x) break;
		for(long long j=0;j<(long long)(v.size());j++)
			if(v[j]>=a[i].x) s[j]++,v[j]-=a[i].x;
	}
	for(long long i=0;i<(long long)(v.size());i++) maxn=max(maxn,cnt-i+s[i]);
	printf("%lld",maxn);
	return 0;
}
