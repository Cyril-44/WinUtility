#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e6+5;
int n;
long long m,f[M];
long long a[N],b[N];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(long long j=1;(j-j/2)*a[i]+(j/2)*b[i]<=m;j++){
			long long num=(j-j/2)*a[i]+(j/2)*b[i];
			for(long long h=m;h>=num;h--){
				f[h]=max(f[h],f[h-num]+j);
			}
		}
	}
	cout<<f[m];
	return 0;
}
