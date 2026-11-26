#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
    inr c,f;
    cin>>c>>f;
    for(int i=1;i<=f;i++){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int sm=1;
        for(int i=1;i<=n;i++){
            sm=sm*2%998244353;
        }
        cout<<sm<<endl;
    }
	return 0;
}
