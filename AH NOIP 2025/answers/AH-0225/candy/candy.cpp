#include<bits/stdc++.h>
using namespace std;
const int N=100001;
long long n,m;
long long a[2][N],b[N];
long long ans=0;
bool cmp(long long a,long long b){
	return a<b;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	long long minn=m+1,c;
	for(int i=1;i<=n;i++){
		cin>>a[0][i]>>a[1][i];
		if(minn>=a[0][i]+a[1][i]){
			if(minn>a[0][i]+a[1][i])c=m+1;
			else c=min(c,a[1][i]);
			minn=a[0][i]+a[1][i];
		}
		b[i]=a[0][i];
	}
	ans=(m-minn)/minn;
	ans*=2;
	sort(b+1,b+1+n,cmp);
	long long x=m%minn,ans1=0;
	x+=minn;
	for(int i=1;i<=n;i++){
		if(x-b[i]>=0){
			x-=b[i];
			ans1++;
		}
		else{
			break;
		}
	}
	if(x+1-c)ans1++;
	ans+=ans1;
	cout<<ans;
	return 0;
}
