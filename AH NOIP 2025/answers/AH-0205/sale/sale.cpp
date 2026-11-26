#include<bits/stdc++.h>
#define INF 998244353
using namespace std;
int c,t;
int n,m;
int a[1001001];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<(m*2/a[1])%INF;
	}
	return 0;
}
