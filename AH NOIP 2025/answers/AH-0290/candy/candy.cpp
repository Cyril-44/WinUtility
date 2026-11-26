/*sorai saki suki uwu*/
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;
const int mxn=1e5+10;
struct cy{
	ll a,b,sum;
}c[mxn];
ll n;
ll m,ans=0,tpm=1e9+1;
bool bi1(cy x,cy y){
	if(x.sum!=y.sum) return x.sum<y.sum;
	else return x.a<=y.a;
}
bool bi2(cy x,cy y){
	return x.a<=y.a;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i].a>>c[i].b,c[i].sum=c[i].a+c[i].b,tpm=min(tpm,c[i].a);
	sort(c+1,c+1+n,bi1);
	ans+=ceil(m/c[1].sum)*2,m%=c[1].sum;
	sort(c+1,c+1+n,bi2);
	for(int i=1;i<=n;i++){
		if(m<c[i].a) break;
		else ans++,m-=c[i].a;
	}
	cout<<ans;
	return 0;
}
