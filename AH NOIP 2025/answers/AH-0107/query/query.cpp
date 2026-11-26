#include<bits/stdc++.h>
using namespace std;
long long mod=1;
int n,q;
long long ans;
long long a[100005];
long long t[400005];
void build(int fa,int l,int r){
	if(l==r){
		t[fa]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(fa<<1,l,mid);
	build(fa<<1|1,mid+1,r);
	t[fa]=t[fa<<1]+t[fa<<1|1];
}
long long query(int fa,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return t[fa];
	}
	int mid=(l+r)>>1;
	long long anss=0;
	if(mid>=ql){
		anss+=query(fa<<1,l,mid,ql,qr);
	}
	if(mid<qr){
		anss+=query(fa<<1|1,mid+1,r,ql,qr);
	}
	return ans;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	for(int i=1;i<=64;i++){
		mod*=2;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	cin>>q;
	while(q--){
		int mnl,mxl;
		cin>>mnl>>mxl;
		ans=0;
		for(int i=1;i<=n;i++){
			long long tt=-0x3f3f3f3f;
			for(int len=mnl;len<=mxl;len++){
				for(int l=i-len+1;l<=i;l++){
					int r=l+len-1;
					tt=max(tt,query(1,1,n,l,r));
				}
			}
			long long mm=i*tt;
			mm=mm%mod;
			ans^=mm;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
