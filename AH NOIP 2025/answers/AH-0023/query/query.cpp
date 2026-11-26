#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int N=50000;
int n,m,a[N+5],lg[N+5];
deque<int>q;
long long s[N+5],cur;
long long mx[N+5][20];
long long query(int l,int r){
	r=min(r,n);
	if(l>r)return -1e18;
	int len=lg[r-l+1];
	return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
unsigned long long ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;lg[0]=-1;
	for(int i=1;i<=n;++i)cin>>a[i],s[i]=s[i-1]+a[i],lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i)mx[i][0]=s[i];
	for(int j=1;1<<j<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	cin>>m;
	for(int C=0,l,r;C<m;++C){
		cin>>l>>r;ans=0;
		for(int i=1;i<=n;++i){
			cur=-1e18;
			for(int j=max(i-r+1,1);j<=i;++j)
				cur=max(cur,query(max(j+l-1,i),j+r-1)-s[j-1]);
			ans^=i*cur;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
