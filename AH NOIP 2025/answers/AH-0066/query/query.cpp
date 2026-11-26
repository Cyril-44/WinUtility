#include<bits/stdc++.h>
using namespace std;
#define N 50005
#define ull unsigned long long
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,q,a[N];
long long sum[N],tre[N<<2],tag[N<<2];
inline void pushdown(int k,int l,int r,int mid){
	tre[k<<1]=max(tre[k<<1],tag[k]);tre[k<<1|1]=max(tre[k<<1|1],tag[k]);
	tag[k<<1]=max(tag[k<<1],tag[k]);tag[k<<1|1]=max(tag[k<<1|1],tag[k]);
	tag[k]=-1e18;
}
inline void add(int k,int l,int r,int x,int y,long long z){
	if (x<=l&&r<=y){tre[k]=max(tre[k],z);tag[k]=max(tag[k],z);return ;}
	int mid=(l+r)>>1;pushdown(k,l,r,mid);
	if (x<=mid)add(k<<1,l,mid,x,y,z);
	if (y>mid)add(k<<1|1,mid+1,r,x,y,z);
	tre[k]=max(tre[k<<1|1],tre[k<<1]);
}
inline ull ask(int k,int l,int r){
	if (l==r){return 1ull*tre[k]*l;}
	ull ans=0;
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	ans^=ask(k<<1,l,mid);
	ans^=ask(k<<1|1,mid+1,r);
	return ans;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=in();
	for (int i=1;i<=n;i++)a[i]=in(),sum[i]=sum[i-1]+a[i];
	q=in();
	while (q--){
		int l=in(),r=in();
		memset(tre,-0x3f,sizeof tre);memset(tag,-0x3f,sizeof tag);
		for (int i=l;i<=r;i++)
			for (int j=1;j+i-1<=n;j++)
				add(1,1,n,j,j+i-1,sum[j+i-1]-sum[j-1]);
		printf ("%llu\n",ask(1,1,n));
	}
	return 0;
}
