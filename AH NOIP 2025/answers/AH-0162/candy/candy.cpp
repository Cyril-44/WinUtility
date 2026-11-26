#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100010][3],cost1[100010],cost2[100010],ans;
int main () {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i][1]>>a[i][2];
		cost1[i]=a[i][1];
		cost2[i]=a[i][1]+a[i][2];
	}
	sort(cost1+1,cost1+n+1);
	sort(cost2+1,cost2+n+1);
	int i=1;
	for (;i<=n;i++) {
		if (cost1[i]*2<cost2[1]&&m>=cost1[i]) {
			m-=cost1[i];
			ans++;
		} else {
			break;
		}
	}
	int num=m/cost2[1]*2;
	ans+=num;
	m%=cost2[1];
	bool flag=true;
	if (m+cost1[i-1]-cost2[1]>=0) {
		ans++;
		m=m+cost1[i-1]-cost2[1];
		flag=false;
	}
	if (m>0&&flag) {
		for (;i<=n&&m-cost1[i]>=0;i++) {
			m-=cost1[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
