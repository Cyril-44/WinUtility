#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int a[1000005],b[1000005];
int cnt[50005];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+a[i];
	cin>>q;
	while(q--){
		int l,r,s=0;
		unsigned long long ans=0;
		deque<int> q;
		cin>>l>>r;
		for(int i=r;i<=n;i++)cnt[i]=b[i]-b[i-r];
		for(int i=n,c=1;i>0;i--,c++){
			while(i>=r&&!q.empty()&&cnt[i]>=cnt[q.back()])q.pop_back();
			while(!q.empty()&&i+r-1<q.front())q.pop_front();
			q.push_back(i);
			s=cnt[q.front()];
			ans=(ans^(s*c));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//!noip@Nov29,2025:dream
/*
4
2 4 ‐5 1
3
1 2
3 4
1 4
*/
