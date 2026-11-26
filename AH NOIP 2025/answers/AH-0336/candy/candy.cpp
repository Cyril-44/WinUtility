#include<bits/stdc++.h>
using namespace std;
int n,i;
long long m,mk,ans;
struct cdy{
	long long x,y,sm;
	int tot;
}a[100010],k;
bool cmp(cdy p,cdy q){
	if(p.sm==q.sm)
		return p.x<q.x;
	return p.sm<q.sm;
}
bool cmp2(cdy p,cdy q){
	return p.x<q.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].sm=a[i].x+a[i].y;
		a[i].tot=i;
	}
	i--;
	sort(a+1,a+1+n,cmp);
	k=a[1];
	sort(a+1,a+1+n,cmp2);
	mk=m;
	bool flag=0;
	for(i=1;i<=n;i++){
		if(a[i-1].x+a[i].x<k.sm && mk>=a[i-1].x+a[i].x){
			mk-=a[i].x;
			ans++;
			if(a[i].tot==k.tot)
				flag=1;
		}
		else
			break;
	}
	i--;
	ans+=(mk/k.sm)*2;
	mk%=k.sm;
	for( ;i>=1;i--){
		if(a[i].tot==k.tot)
			continue;
		if(mk+a[i].x>=k.sm){
			ans++;
			mk=mk+a[i].x-k.sm;
			break;
		}
	}
	if((!flag && mk>=k.x) || (flag && mk>=k.y))
		ans++;
	cout<<ans<<endl;
    return 0;
}
