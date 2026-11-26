#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],x,y;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	while(m--){
		cin>>x>>y;
		int ans=0;
		for(int i=x;i<=y;i++){
			ans^=a[i];
		}
	}
	return 0;
}
//!noip@Nov29,2025:dream
