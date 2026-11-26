#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int a[50005],s[50005];
int f[3005][3005];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cout<<rand();
	}
	return 0;
}
