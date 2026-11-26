#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,m,a[N][2],ans;
int low,val=1e18;
vector<int>s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		if(a[i][0]+a[i][1]<val){
			val=a[i][0]+a[i][1];
			low=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i][0]*2<=val){
			if(m-a[i][0]<0)continue;
			m-=a[i][0];
			ans++;
			// s.push_back(a[i][1]);
		}else
		s.push_back(a[i][0]);
	}
	int k=m/val;
	m%=val;
	ans+=k*2;
	sort(begin(s),end(s));
	for(auto i:s){
		if(m-i<0)break;
		m-=i;
		ans++;
	}
	cout<<ans;
	return 0;
}