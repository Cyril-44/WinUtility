#include<bits/stdc++.h>
using namespace std;
const int N=8010;
int t,n,m,p[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            cin>>p[i];
        }
        cout<<n*m-m+1<<endl;
	}
	return 0;
}

