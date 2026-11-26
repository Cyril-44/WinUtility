#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=50010;
ll n,a[maxn],q,l,r,sum[maxn];
ull ans;
struct segment{
	ll mx[4*maxn],tag[4*maxn];
	void build(int x,int l,int r){
		mx[x]=-1e18,tag[x]=-1e18;
		if(l==r){
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
	}
	void push_up(int x){
		mx[x]=max(mx[x*2],mx[x*2+1]);
	}
	void push_down(int x){
		if(tag[x]!=-1e18){
			tag[x*2]=max(tag[x*2],tag[x]);
			mx[x*2]=max(mx[x*2],tag[x]);
			tag[x*2+1]=max(tag[x*2+1],tag[x]);
			mx[x*2+1]=max(mx[x*2+1],tag[x]);
		}
	}
	void update(int x,int l,int r,int ql,int qr,ll d){
		if(l>=ql&&r<=qr){
			tag[x]=max(tag[x],d);
			mx[x]=max(mx[x],d);
			return;
		}
		push_down(x);
		int mid=(l+r)/2;
		if(ql<=mid){
			update(x*2,l,mid,ql,qr,d);
		}
		if(qr>mid){
			update(x*2+1,mid+1,r,ql,qr,d);
		}
		push_up(x);
	}
	ll query(int x,int l,int r,int q){
		if(l==r){
			return mx[x];
		}
		push_down(x);
		int mid=(l+r)/2;
		if(q<=mid){
			return query(x*2,l,mid,q);
		}
		return query(x*2+1,mid+1,r,q);
	}
}tr;	
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	//ull a=-1;
	//cout<<a<<endl;
	cin>>q;//ll cnt=0;
	while(q--){
		ans=0;
		tr.build(1,1,n);
		cin>>l>>r;
		
		for(int i=1;i+l-1<=n;i++){
			for(int j=i+l-1;j<=min(n,i+r-1);j++){
				//cnt++;
				tr.update(1,1,n,i,j,sum[j]-sum[i-1]);
			}
		}
		for(int i=1;i<=n;i++){
			ull k=tr.query(1,1,n,i)*i;
			ans=ans^k;
		}
		cout<<ans<<'\n';
	}
	//cout<<cnt;
	return 0;
}	
