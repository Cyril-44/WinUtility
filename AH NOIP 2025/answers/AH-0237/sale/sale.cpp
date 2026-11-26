#include<bits/stdc++.h>
using namespace std;
const int N=5000+10,M=998244353;
struct S{
	long long a;
	double w;
	
}s[N];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long  maxx=-1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a;
			maxx=max(maxx,s[i].a);
		}
		cout<<((maxx%M*3%M)/5);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
