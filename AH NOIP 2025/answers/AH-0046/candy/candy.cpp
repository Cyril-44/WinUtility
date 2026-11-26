#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
int cnt;
int tmp;
struct node {
	int x;
	int y;
	int sum;
	bool flag;
	int tot;
	bool fflag;
} a[200005],b[200005];
bool cmp1 (node x,node y) {
	return x.sum<y.sum;
}
bool cmp2 (node x,node y) {
	return x.x<y.x;
}
signed main () {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
		a[i].sum=a[i].x+a[i].y;
		a[i].flag=true;
		a[i].fflag=true;
		/*
		if(a[i].y>a[i].x) {
			//a[i].fflag=false;
			a[++cnt]=a[i];
			a[cnt].sum=a[i].x*2;
			a[cnt].flag=false;
			a[cnt].fflag=true;
			a[cnt].tot=i;
		}
		*/
		b[i]=a[i];
		a[++cnt]=a[i];
		a[cnt].sum=a[i].x*2;
		a[cnt].flag=false;
		a[cnt].fflag=true;
		a[cnt].tot=i;
	}
	sort(a+1,a+cnt+1,cmp1);
	for(int i=1;i<=n;i++) {
		//cout<<a[i].x<<" "<<a[i].y<<" "<<m<<endl;
		if(a[i].flag) {
			ans+=(m/a[i].sum)*2;
			m=m%a[i].sum;
		}
		else {
			if(m>=a[i].x) {
				a[i].fflag=false;
				swap(b[a[i].tot].x,b[a[i].tot].y);
				m-=a[i].x;
				ans++;
			}
		}
		//cout<<a[i].x<<" "<<a[i].y<<" "<<m<<" "<<ans<<endl;
	}
	/*
	for(int i=1;i<=cnt;i++) {
		if(!a[i].fflag) {
			b[a[i].tot].x=b[a[i].tot].y;
		}
	}
	//cout<<tmp<<endl;
	cout<<m<<endl;
	for(int i=1;i<=n;i++) {
		cout<<b[i].x<<" "<<b[i].y<<endl;
	}
	*/
	//cout<<m<<endl;
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;i++) {
		//cout<<b[i].x<<" "<<b[i].y<<endl;
		if(b[i].x<=m) {
			m-=b[i].x;
			ans++;
		}
	}
	/*
	cout<<m<<endl;
	sort(b+1,b+n+1,cmp1);
	for(int i=1;i<=n;i++) {
		cout<<b[i].x<<" "<<b[i].y<<endl;
	}
	*/
	cout<<ans;
	return 0;
}
/*
3 15
1 7
2 3
3 1
*/
