#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int N=5e4+5;
int sum[N],a[N];
int st[N][25],lg[N];
int get_max(int l,int r)
{
	int len=lg[r-l+1];
	return max(st[l][len],st[r-(1<<len)+1][len]);
}
struct SGT
{

int tag[N<<1];
void build(int num,int l,int r)
{
	tag[num]=-1e9;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(num*2,l,mid);
	build(num*2+1,mid+1,r);
}
void modify(int num,int l,int r,int pl,int pr,int x)
{
	if(l>=pl&&r<=pr)
	{
		tag[num]=max(tag[num],x);
		return ;
	}
	int mid=(l+r)>>1;
	if(pl<=mid) modify(num*2,l,mid,pl,pr,x);
	if(pr>mid) modify(num*2+1,mid+1,r,pl,pr,x);
}
void get_ans(int num,int l,int r,unsigned long long &ans)
{
	if(l==r)
	{
		ans^=1ull*l*tag[num];
		return ;
	}
	tag[num*2]=max(tag[num*2],tag[num]);
	tag[num*2+1]=max(tag[num*2+1],tag[num]);
	int mid=(l+r)>>1;
	get_ans(num*2,l,mid,ans);
	get_ans(num*2+1,mid+1,r,ans);
}

}t;
signed main(){
#if __MY_TEST__
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) st[i][0]=sum[i];
	for(int j=1;j<=20;j++) for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	int q=read();
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		unsigned long long ans=0;
		t.build(1,1,n);
		for(int j=1;j<=n;j++)
		{
			for(int len=l;len<=r;len++)
			{
				int k=j+len-1;
				if(k>n) break;
				int s=sum[k]-sum[j-1];
				t.modify(1,1,n,j,k,s);
			}
		}
		t.get_ans(1,1,n,ans);
		cout<<ans<<'\n';
	}
}

