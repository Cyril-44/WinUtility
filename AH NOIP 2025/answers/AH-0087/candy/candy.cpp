#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0; re char c;
	while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48);
	while((c=getchar())>'-');
	return x;
}
inline void Min(int &a,int b) {if(a>b) a=b;}
const int N=1e5+5;
struct Candy {
	int x,y;
	bool operator < (const Candy& X) const {
		if(x!=X.x) return x<X.x;
		return y<X.y;
	}
}a[N];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int minc=INT_MAX,mins=INT_MAX,n; long long m,_ans=0,ans=0;
	scanf("%d%lld",&n,&m);
	for(re int i=0;i<n;++i)
		a[i].x=read(),a[i].y=read(),
		Min(minc,a[i].x+a[i].y);
	sort(a,a+n);
	int p=0;
	for(re int i=0;i<n;++i)
		if(a[i].x+a[i].y==minc && a[i+1].x+a[i+1].y!=minc)
			p=i;
	bool buy=false,pd=false; int last;
	for(re int i=0;i<n-1;++i)
		if(i&1)
			if(a[i-1].x+a[i].x<minc)
			{
				m-=a[i-1].x+a[i].x,ans+=2;
				pd=true,last=a[i].x;
				if(i==p || i==p+1)
					Min(mins,a[p].y),buy=true;
			}
			else Min(mins,a[i-1].x),Min(mins,a[i].x);
	if(!buy)
	{
		_ans=ans+(m/minc<<1);
		Min(mins,a[p].x);
		if(m%minc>=mins) ++_ans;
		m+=last,m-=a[p].x,mins=a[p].y;
		if(!pd || m<0) return printf("%lld",_ans),0;
	}
	ans+=m/minc<<1;
	printf("%lld",max(_ans,m%minc>=mins?ans+1:ans));
	return 0;
}
