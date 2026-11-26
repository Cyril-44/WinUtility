#include<bits/stdc++.h>
using namespace std;
int m,n,a[10001],ans,mina=1e5,fg,c,t,maxa=0;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			cin>>a[i];
			mina=min(mina,a[i]);
			maxa=max(maxa,a[i]);
		}
		if(maxa<=mina*2){
		}
	}
	
	return 0;
}


