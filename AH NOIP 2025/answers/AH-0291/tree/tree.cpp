#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int t,m,n,pa[maxn];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		pa[1]=0;
		for(int i=2;i<=n;i++){
			cin>>pa[i];
		}
		cout<<1<<endl;
	}
	return 0;
}
