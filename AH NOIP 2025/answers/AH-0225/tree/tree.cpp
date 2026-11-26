#include<bits/stdc++.h>

using namespace std;
int t,a[10001];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		long long ans=0;
		int n,m,x=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=n;i++){
			if(a[i]==a[1])x++;
			else{
				break;
			}
		}
		ans=x*a[x]+n-x;
		cout<<ans<<"\n";
	}
	return 0;
}
