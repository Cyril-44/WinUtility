#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int m,T;
	cin>>m>>T;
	while(T--){
		int n,m,sum=1;
		cin>>n>>m;
		for(int i=1,a;i<=n;i++){
			cin>>a;
		}
		int x=2;
		while(n!=0){
			if(n%2==1){
				sum*=x;
			}
			x*=x;
			n/=2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
