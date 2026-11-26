#include<bits/stdc++.h>
using namespcae std;
const int N=1e5+5;
int pre[N];
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    int t; cin>>t;
    while(t--) {
	    int n,m; cin>>n>>m;
	    for(int i=1;i<=n;i++) {cin>>pre[i];}
	    if(m==2) cout<<2*n<<"\n";
	}
    return 0;
}
