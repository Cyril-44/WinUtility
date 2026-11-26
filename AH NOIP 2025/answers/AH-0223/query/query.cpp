#include<bits/stdc++.h>
using namespace std;
int n,m,a[50004];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int l;
		cin>>l>>l;
		cout<<a[l]<<endl;
	}
	return 0;
}

