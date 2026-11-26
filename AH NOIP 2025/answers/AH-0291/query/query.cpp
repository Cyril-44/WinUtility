#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int n,q,a[maxn];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int v,w;
		cin>>v>>w;
		cout<<v*w<<endl;
	}
	return 0;
}
