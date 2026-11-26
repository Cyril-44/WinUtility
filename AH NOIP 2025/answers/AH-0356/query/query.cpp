#include<bits/stdc++.h>
#define i128 __int128_t
#define int long long 
using namespace std;
const i128 mod=pow(2,64);
const int N=5e4+10;
int n,Q,a[N],s[N],maxv[N];
void write(i128 x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
freopen("query.in","r",stdin);
freopen("query.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	s[i]=s[i-1]+a[i];
}
cin>>Q;
while(Q--){
	int L,R;
	cin>>L>>R;
	memset(maxv,0,sizeof(int[n+1]));
	for(int l=1;l<=n;l++){
		for(int r=l+L-1;r<=min(n,l+R-1);r++){
			for(int i=l;i<=r;i++){
				maxv[i]=max(maxv[i],s[r]-s[l-1]);
			}
		}
	}
	i128 res=0;
	for(int i=1;i<=n;i++) res=res^((((i128)i*maxv[i]%mod)+mod)%mod);
		if(!res) cout<<0<<"\n";
	else write(res);
	putchar('\n');
}
return 0;
}
