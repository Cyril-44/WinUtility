#include<bits/stdc++.h>
using namespace std;
int n;
int x[100005],y[100005],minn;
long long m,tmp1,tmp2,ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    minn=2000000005;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        minn=min(minn,x[i]+y[i]);
    }
    sort(x,x+n);
    for(int i=0;i<n;i++){
		tmp2=tmp1+((long long)(m/(1ll*minn)))*2;
		if(m-((long long)(m/(1ll*minn)))*minn>=x[i]) tmp2++;
		ans=max(ans,tmp2);
        if(m>=x[i]){
			m-=1ll*x[i];
			tmp1++;
		}
	}
	tmp2=tmp1+((long long)(m/(1ll*minn)))*2;
	ans=max(ans,tmp2);
    cout<<ans;
    return 0;
}
