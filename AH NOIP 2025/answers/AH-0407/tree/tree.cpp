#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,sum;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x;
			sum+=x;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//!noip@Nov29,2025:dream
