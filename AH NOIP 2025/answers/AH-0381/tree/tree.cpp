#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,m;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++)cin>>m;
		cout<<n+m+rand()<<'\n';
	}
	return 0;
}
