#include<bits/stdc++.h>
using namespace std;
struct candy{
	int sum,fi;
}candys[100010];
int n,mini=2000000000,minn,ans;
long long m;
bool cmp(candy a,candy b){
	return a.fi<b.fi;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		candys[i].fi=a;
		candys[i].sum=a+b;
		mini=min(mini,a+b);
	}
	sort(candys,candys+n,cmp);
	for(int i=0;i<n;i++){
		if(candys[i].sum==mini){
			minn=i;
			break;
		}
	}
	int nans=0,nowc=0;
	for(int i=0;m>=nowc;i++){
		m-=nowc;
		if(i%2==0)
			nowc=candys[minn].fi;
		else
			nowc=candys[minn].sum-candys[minn].fi;
		nans=i;
		int now=m;
		for(int j=0;now>=candys[j].fi&&candys[j].fi<nowc&&j<n;j++){
			if(j==minn)continue;
			now-=candys[j].fi;
			nans++;
		}
		ans=max(ans,nans);
	}
	cout<<ans<<endl;
	return 0;
}
