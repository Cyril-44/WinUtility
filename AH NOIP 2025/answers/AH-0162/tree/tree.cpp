#include <bits/stdc++.h>
using namespace std;
vector <int> s[8010];
long long t,n,l,sn[8010],a[8010],num[8010],ans;
void dfs (int x) {
	if (sn[x]==0) {
		num[x]=0;
		return;
	}
	bool flag=true;
	for (int i=0;i<sn[x];i++) {
		dfs(s[x][i]);
		if (num[s[x][i]]!=0) {
			flag=false;
		}
	}
	if (flag) {
		num[x]=sn[x]+1;
		ans+=num[x]+1;
	} else {
		for (int i=0;i<sn[x];i++) {
			if (num[s[x][i]]==0) ans++;
			num[x]=max(num[x],num[s[x][i]]+1);
		}
		ans+=num[x];
	}
	return;
}
int main () {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n>>l;
		ans=0;
		for (int i=1;i<=n;i++) {
			sn[i]=num[i]=0;
		}
		for (int i=2;i<=n;i++) {
			cin>>a[i];
		}
		for (int i=2;i<=n;i++) {
			sn[a[i]]++;
			s[a[i]].push_back(i);
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
