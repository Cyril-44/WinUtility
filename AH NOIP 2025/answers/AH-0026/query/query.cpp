#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 50005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int n,a[N],q;
ll s[N];
struct pnode{
	int l,r;
	ll ma,add;
}tr[N*4];
__int128 mod=1;
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	tr[u].ma=tr[u].add=-1e18;
	if(l==r)return;
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
}
void pj(int u){
	tr[u*2].ma=max(tr[u*2].ma,tr[u].add);
	tr[u*2+1].ma=max(tr[u*2+1].ma,tr[u].add);
	tr[u*2].add=max(tr[u*2].add,tr[u].add);
	tr[u*2+1].add=max(tr[u*2+1].add,tr[u].add);
	tr[u].add=-1e18;
}
void sig(int u,int al,int ar,ll add){
	int l=tr[u].l,r=tr[u].r;
	if(al<=l&&r<=ar){
		tr[u].ma=max(tr[u].ma,add);
		tr[u].add=max(tr[u].add,add);
		return;
	}
	pj(u);
	int mid=(l+r)/2;
	if(al<=mid)
		sig(u*2,al,ar,add);
	if(mid<ar)
		sig(u*2+1,al,ar,add);
	tr[u].ma=max(tr[u*2].ma,tr[u*2+1].ma);
}
ll ask(int u,int k){
	int l=tr[u].l,r=tr[u].r;
	if(l==r){
		int k=tr[u].ma;
		tr[u].ma=tr[u].add=-1e18;
		return k;
	}
	pj(u);
	tr[u].ma=tr[u].add=-1e18;
	int mid=(l+r)/2;
	if(k<=mid)return ask(u*2,k);
	else return ask(u*2+1,k);
}
void wr(unsigned long long x){
	if(x==0)return;
	wr(x/10);
	putchar(x%10+'0');
}
unsigned long long ans=0;
void build1(int u,int l,int r){
	if(l==r){
		ans^=(l*tr[u].ma);
		tr[u].ma=tr[u].add=-1e18;
		return;
	}
	pj(u);
	tr[u].ma=tr[u].add=-1e18;
	int mid=(l+r)/2;
	build1(u*2,l,mid);
	build1(u*2+1,mid+1,r);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for(int i=1;i<=64;i++)mod*=2; 
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+read();
	q=read();
	int kkk=0;
	build(1,1,n);
	while(q--){
		int l=read(),r=read();
		for(int j=l;j<=r;j++)
			for(int k=1;k<=n-j+1;k++)
				sig(1,k,k+j-1,s[k+j-1]-s[k-1]);
		ans=0;
		build1(1,1,n);
		if(ans<0)
			ans+=mod;
		if(ans==0)printf("0");
		else
		wr(ans);
		printf("\n");
	}
	return 0;
}