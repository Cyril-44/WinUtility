#include<bits/stdc++.h>
#define int long long
using namespace std;
struct o{
	int x,y;
}a[1000005];
int n,m,Min=1,ans;
bool cmp(o x,o y){
	return x.x<y.x;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)if(a[i].x+a[i].y<a[Min].x+a[Min].y)Min=i;
	int i,z;
	ans+=m/(a[Min].x+a[Min].y)*2;
	m%=a[Min].x+a[Min].y;
	for(i=1;i<=n&&m>0;i++){
		if(a[i].x>m)break;
		m-=a[i].x;
		ans++;
	}
	for(z=0;i<=n&&z<ans;i++){
		bool f=1;
		for(;i<n&&z<ans;i++){
			if(a[i].x+a[i+1].x<a[Min].x+a[Min].y){
				m+=a[Min].x+a[Min].y-a[i].x-a[i+1].x;
				z+=2,i++;
				f=0;
			}
			else break;
		}
		ans+=m/(a[Min].x+a[Min].y)*2;
		m%=a[Min].x+a[Min].y;
		for(;i<=n&&m>0;i++){
			if(a[i].x>m)break;
			f=0;
			m-=a[i].x;
			ans++;
		}
		if(f)break;
	}
	cout<<ans;
	return 0;
}
