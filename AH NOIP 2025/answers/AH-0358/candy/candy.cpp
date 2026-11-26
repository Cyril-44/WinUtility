#include<bits/stdc++.h>
using namespace std;
struct awa{
	long long a,b;
}p[100005];
int n;
long long minn=1e18+5;
long long m,ans,sum;
priority_queue<long long>mnnb;
vector<long long>d;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b;
		minn=min(p[i].a+p[i].b,minn);
	}
	sort(p+1,p+n+1,[](awa x,awa y){
		return x.a<y.a||(x.a==y.a&&x.b<y.b);
	});
	p[n+1].a=0x7f7f7f7f7f7f7f7f;
	ans=m/minn*2;
	for(int i=1;i<=n;i++){
		sum+=p[i].a;
		mnnb.push(p[i].b);
		d.clear();
		long long ansx=0;
		long long left=m-sum;
		long long yu=left%minn;
		while(!mnnb.empty()&&yu>=mnnb.top()){
			yu-=mnnb.top(); d.push_back(mnnb.top());
			mnnb.pop(); ansx++;
		}
		for(long long v : d)mnnb.push(v);
		ansx+=i+left/minn*2;
		ans=max(ans,ansx);
	}
	cout<<ans<<endl;
	return 0;
}
