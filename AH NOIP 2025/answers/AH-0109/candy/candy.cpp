#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,cnt1,cnt2,yj;
struct stu{
	int x,y,h,f;
}a[100005];
int p,q,z;
bool cmp(stu x,stu y){
	if(x.h!=y.h)
		return x.h<y.h;
	return x.x<y.x;
}
bool cmp2(stu x,stu y){
	return x.x<y.x;
}
bool cmp3(stu x,stu y){
	if(x.f!=y.f) return x.f>y.f;
	return x.y<y.y;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	yj=m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].h=a[i].x+a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	p=a[1].x,q=a[1].y,z=a[1].x+a[1].y;
	a[1].x=0x3f3f3f3f3f3f3f3f,a[1].y=0x3f3f3f3f3f3f3f3f;
	a[n+1].x=0x3f3f3f3f3f3f3f3f,a[n+1].y=0x3f3f3f3f3f3f3f3f;
	sort(a+1,a+n+1,cmp2);
	int flag,k1=a[1].x;
	for(int i=1;i<=n+1;i+=2){
		if(a[i].x+a[i+1].x<=z){
			m-=(a[i].x+a[i+1].x);
			a[i].f=1;
			a[i+1].f=1;
			cnt+=2;
		}
		else{
			flag=i;
			break;
		}
	}
	int k2=a[flag].x;
	cnt+=(m/z)*2;
	m=m-(m/z)*z;
	if(m>=p){
		m-=p;
		cnt++;
	}
	if(m>=a[flag].x){
		m-=a[flag].x;
		a[flag].f=1;
		cnt++;
	}
	sort(a+1,a+n+1,cmp3);
	int flag2=0;
	for(int i=1;i<=n;i++){
		if(a[i].f==1&&m>=a[i].y){
			flag2=1;
			m-=a[i].y;
			cnt++;
		}
	}
	if(flag2==0){
		for(int i=1;i<=n;i++){
			if(a[i].f==0&&(m+k2-a[i].x)>=a[i].y&&a[i].x+k1<=yj){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
