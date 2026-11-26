#include<bits/stdc++.h>
using namespace std;
long long n,m,x[100009],y,z=1e18,ans,cnt=0,sum=0,ymy,tt,i;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>x[i]>>y,z=min(z,x[i]+y);
	sort(x+1,x+n+1),ans=(m/z)*2,m%=z;
	for(i=1;i<=n&&m-x[i]>=0;i++) m-=x[i],sum++;
	tt=ans+sum;
	for(;i<=n&&ans>0;i++){
		ymy+=x[i],cnt++;
		if(ymy>m+z){
			ymy-=x[i],i--,cnt--;
			if(cnt<2) break;
			ans-=2,tt=tt-2+cnt,m=m+z-ymy,ymy=0,cnt=0;
		}
	}
	if(cnt>2) tt=tt-2+cnt;
	cout<<tt;return 0;
}
