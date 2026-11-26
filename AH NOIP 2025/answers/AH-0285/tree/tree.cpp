#include<bits/stdc++.h>
using namespace std;
long long t,n,m,i,p[8009];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n-1;i++)cin>>p[i];
		cout<<n*2-1<<'\n';
	}
	return 0;
}
