#include<bits/stdc++.h>
using namespace std;
long long n,q,i,a[50009],l,r,sum[50009],lazy[50009];
void up(long long i){
	sum[i]=sum[i<<1]+sum[i<<1|1];
}
void build(long long l,long long r,long long i){
	if(l==r)sum[i]=a[l];
	else{
		long long mid=(l+r)>>1;
		build(l,mid,i*2);
		build(mid+1,r,i*2+1);
		up(i);
	}
	lazy[i]=0;
}
void update(long long i,long long jobn,long long v){
	sum[i]+=jobn*v;
	lazy[i]+=v;
}
void down(long long l,long long r,long long i){
	if(lazy[i]!=0){
		long long mid=(l+r)>>1;
		update(l,mid,i<<1);
		update(mid+1,r,i<<1|1);
		lazy[i]=0;
	}
}
long long query(long long jobl,long long jobr,long long l,long long r,long long i){
	if(jobl<=l&&r<=jobr)return sum[i];
	else{
		long long ans=0,mid=(l+r)>>1;
		down(i,mid-l+1,r-mid);
		if(jobl<=mid)ans+=query(jobl,jobr,l,mid,i<<1);
		if(jobr>mid)ans+=query(jobl,jobr,mid+1,r,i<<1|1);
		return ans;
	}
}
void add(long long jobl,long long jobr,long long v,long long l,long long r,long long i){
	if(jobl<=l&&r<=jobr)update(i,r-i+1,v);
	else{
		long long mid=(l+r)>>1;
		down(i,mid-l+1,r-mid);
		if(jobl<=mid)add(jobl,jobr,v,l,mid,i<<1);
		if(jobr>mid)add(jobl,jobr,v,mid+1,r,i<<1|1);
		up(i);
	}
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	cin>>q;
	while(q--){
		cin>>l>>r;
		add(l,r,0,1,n,1);
		cout<<abs(2*query(l,r,1,n,1))<<'\n';
	}
	return 0;
}
