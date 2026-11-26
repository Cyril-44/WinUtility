#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll n,m,ans;
struct nd{
	ll w1,w2;
}a[N];
struct node{
	int t2,fg;
	int id;
}b[N];
struct by1{
	int t1,id;
}c[N];
bool cmp(node k1,node k2){
	if(k1.t2==k2.t2) return k1.fg<k2.fg;
	return k1.t2<k2.t2;
}
bool cmp2(by1 k3,by1 k4){
	return k3.t1<k4.t1;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].w1,&a[i].w2);
		b[i].t2=(a[i].w1+a[i].w2)/2;
		if((a[i].w1+a[i].w2)%2==1) b[i].fg=1;
		b[i].id=i;
		c[i].t1=a[i].w1;
		c[i].id=i;
	}
	sort(b+1,b+1+n,cmp);
	sort(c+1,c+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(c[i].t1>b[1].t2) break;
		if(m%b[1].t2!=0){
			m-=c[i].t1;
			ans++;
		}
		else{
			if(c[i].t1+c[i+1].t1>b[1].t2*2) break;
			else{
				ans+=2;
				m-=(c[i].t1+c[i+1].t1);
				i++;
			}
		}
	}
	if(b[1].fg==0) ans+=(m/b[1].t2);
	else{
		int kf=b[1].t2*2+1;
		ans+=2*(m/kf);
		m-=kf*(m/kf);
		if(m>b[1].t2) ans+=2;
	}
	cout<<ans<<endl;
	return 0; 
}
