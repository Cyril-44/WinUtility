#include<bits/stdc++.h>
using namespace std;
struct o{
	long long a,b;
}a[100005];
bool cmp(o x,o y){
	return x.a<y.a;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m,mn=1e18,h;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].a,&a[i].b);
		h=a[i].a+a[i].b;
		mn=min(mn,h);
	}
	sort(a+1,a+n+1,cmp);
	long long gg,zh;
	long long s=0;
	for(int i=1;i<=n;i+=2){
		if(i+1>n)break;
		gg=a[i].a+a[i+1].a;
		if(m<mn)break;
		if(gg<=mn){
			if(m>=gg){
				m-=gg;
				s+=2;
				zh=a[i].a;
				a[i].a=a[i].b;
				a[i].b=zh;
				zh=a[i+1].a;
				a[i+1].a=a[i+1].b;
				a[i+1].b=zh;
			}else{
				break;
			}
		}else{
			break;
		}
	}
	long long kk=m/mn;
	s=s+kk*2;
	m=m-kk*mn;
	long long zdd=0,xh;
	for(int i=1;i<=n;i++){
		if(a[i].a+a[i].b==mn){
			if(a[i].b>=zdd){
				zdd=a[i].b;
				xh=i;
			}
		}
	}
	s--;
	m=m+zdd;
	zh=a[xh].a;
	a[xh].a=a[xh].b;
	a[xh].b=zh;
	sort(a+1,a+n+1,cmp);
	while(m>=a[1].a){
		m-=a[1].a;
		s++;
		zh=a[1].a;
		a[1].a=a[1].b;
		a[1].b=zh;
		sort(a+1,a+n+1,cmp);
	}
	printf("%lld",s);
	return 0;
}
