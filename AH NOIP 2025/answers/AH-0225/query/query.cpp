#include<bits/stdc++.h>

using namespace std;
long long D=9283475928753293879ll;
long long a[50001];
signed main(){
	/*freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);*/
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<n^((a[x]*a[x])%D);
	}
	return 0;
}
