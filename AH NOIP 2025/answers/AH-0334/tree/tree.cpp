#include<bits/stdc++.h>
using namespace std;
const int N=8010;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,m,x;cin>>n>>m;
		for(int i=1;i<n;i++) cin>>x;
		cout<<n*2-m+1<<'\n';
	}
	return 0;
}
