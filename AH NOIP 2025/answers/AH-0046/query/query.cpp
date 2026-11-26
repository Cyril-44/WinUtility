#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f;
int n;
int a[50005];
int s[3005][3005];
int sum[3005];
int t[12005][3005];
int Q;
int l;
int r;
unsigned long long ans;
void up (int u,int k) {
	t[u][k]=max(t[u<<1][k],t[u<<1|1][k]);
	return ;
}
void build (int u,int l,int r,int k) {
	if(l==r) {
		t[u][k]=s[k][l];
		return ;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid,k);
	build(u<<1|1,mid+1,r,k);
	up(u,k);
	return ;
}
int query (int u,int l,int r,int L,int R,int k) {
	if(l>=L&&r<=R) {
		return t[u][k];
	}
	int mid=(l+r)>>1,tot=-inf;
	if(mid>=L) {
		tot=query(u<<1,l,mid,L,R,k);
	}
	if(mid<R) {
		tot=max(tot,query(u<<1|1,mid+1,r,L,R,k));
	}
	return tot;
}
deque<int> q;
signed main () {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout<<-1*1llu<<endl;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		//cout<<a[i]<<" "<<flush;
		sum[i]=sum[i-1]+a[i];
		for(int j=1;j<=n;j++) {
			s[i][j]=-inf;
		}
	}
	/*
	for(int i=1;i<=n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<n<<endl;
	*/
	for(int i=1;i<=n;i++) {
		for(int j=1;j+i-1<=n;j++) {
			for(int k=max(1ll,j-i+1);k<i+j;k++) {
				s[k][i]=max(s[k][i],sum[j+i-1]-sum[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(max(i,n-i+1)<j) {
				s[i][j]=-inf;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++) {
		build(1,1,n,i);
	}
	cin>>Q;
	while(Q--) {
		cin>>l>>r;
		ans=0;
		for(int i=1;i<=n;i++) {
			ans=ans|(query(1,1,n,l,r,i)*1llu);
		}
		cout<<ans<<endl;
	}
	while(1);
	return 0;
}
/*
4
2 4 -5 1
3
1 2
3 4
1 4
*/
