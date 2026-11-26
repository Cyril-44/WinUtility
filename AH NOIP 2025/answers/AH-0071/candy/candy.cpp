#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,minn;
long long a[100005],b[100005];
// !noip@Nov29,2025:dream
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(minn==0) minn=a[i]+b[i];
        else minn=min(minn,a[i]+b[i]);
	}
	sort(a+1,a+n+1);
	ans=(m/minn)*2;
	long long sum=0,k=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]; k++;
		if(sum>m) break;
		ans=max(ans,k+((m-sum)/minn)*2);
	}
	cout<<ans;
    return 0;
}
