#include <bits/stdc++.h>
using namespace std;
long long n,m,m1,m2,m3,t,k,k1,k2,k3,cnt,cnt1,cnt2,cnt3,minn;
struct cd{
	long long x,y,z,p;
}a[100005];
bool cmp(cd x1,cd y1){
	return x1.x<y1.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	t=1;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
		a[i].p=i;
		a[i].z=a[i].x+a[i].y;
		if(a[i].z<a[t].z)
			t=i;
	}
	minn=a[t].z;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
		if(a[i].p==t){
			t=i;
			break;
		}
	for(k=1;k<=n;k+=2){
		if(k==t||k+1==t)
			++k;
		if(a[k].x+a[k+1].x>=minn||a[k].x==0||a[k+1].x==0){
			break;
		}
		m-=a[k].x;
		m-=a[k+1].x;
		if(m<0){
			m+=a[k].x;
			m+=a[k+1].x;
			break;
		}
		cnt+=2;
	}
	cnt+=long(m/minn)*2;
	m-=long(m/minn)*minn;
	cnt1=cnt-1;
	m1=m+a[t].y;
	cnt2=cnt-2;
	m2=m+minn;
	cnt3=cnt-4;
	m3=m+minn+minn;
	if(k>t){
		m-=a[t].x;
		if(m>=0)
			++cnt;
	}
	k1=k;
	k2=k;
	k3=k;
	if(k3>t){
		m3-=a[t].x;
		if(m3>=0)
			++cnt3;
	}
	for(;k<=n;++k){
		m-=a[k].x;
		if(m<0)
			break;
		++cnt;
	}
	for(;k1<=n;++k1){
		if(t==k1)
			continue;
		m1-=a[k1].x;
		if(m1<0)
			break;
		++cnt1;
	}
	for(;k2<=n;++k2){
		m2-=a[k2].x;
		if(m2<0)
			break;
		++cnt2;
	}
	for(;k3<=n;++k3){
		m3-=a[k3].x;
		if(m3<0)
			break;
		++cnt3;
	}
	cout<<max(max(cnt,cnt3),max(cnt1,cnt2))<<endl;
	return 0;
}
