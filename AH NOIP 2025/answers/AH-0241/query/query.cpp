#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
#define ll long long
ll a[N],s[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		ll maxn=-1e10;
		for(int i=1;i<=len;i++){
			for(int j=1;j+i-1<=n;j++){
				maxn=max(maxn,s[j+i-1]-s[j-1]);
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
