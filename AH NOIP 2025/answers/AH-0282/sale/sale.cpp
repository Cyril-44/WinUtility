#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t,d=0,num=0,z=1;
	int a[100001];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,m;
	    cin>>n>>m;
	    for(int i=1;i<=n;i++){
		    cin>>a[i];
		    if(a[i]==a[i-1]){
				num++;
			}
			d++;
		}
		z*=2;
	}
	if(num==d-1){
		cout<<z;
	}
	return 0;
}
