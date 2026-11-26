#include<bits/stdc++.h>
using namespace std;
//L>=R-L直接左右各贡献一次即可
typedef long long ll;
typedef unsigned long long ull;
const int N=5e4+3;
int n,Q,a[N],ff[3005][3005],fmx[N][6][32],q[N],hd,tl;ll s[N],b[N],smx[16][N],smi[16][N],d1[N],d2[N];
void work1(int len){
	hd=1;tl=0;
	ull res=0;
	for(int i=1;i<=n;i++){
		while(hd<=tl&&i-q[hd]+1>len)hd++;
		if(i+len-1<=n){
			b[i]=s[i+len-1]-s[i-1];
			while(hd<=tl&&b[i]>=b[q[tl]])tl--;
			q[++tl]=i;
		}
		res^=(1llu*i*b[q[hd]]);
	}
	printf("%llu\n",res);
}
ll qmx(int l,int r){
	int k=__lg(r-l+1);
	return max(smx[k][l],smx[k][r-(1<<k)+1]);
}
ll qmi(int l,int r){
	int k=__lg(r-l+1);
	return min(smi[k][l],smi[k][r-(1<<k)+1]);
}
struct seg{
	ll mx[12005];
	void build(int o,int ct,int l,int r){
		if(l==r){mx[ct]=ff[o][l];return;}
		int mid=l+r>>1;
		build(o,ct<<1,l,mid);build(o,ct<<1|1,mid+1,r);
		mx[ct]=max(mx[ct<<1],mx[ct<<1|1]);
	}
	int qry(int ct,int l,int r,int sl,int sr){
		if(sl<=l&&r<=sr)return mx[ct];
		int mid=l+r>>1;
		if(sr<=mid)return qry(ct<<1,l,mid,sl,sr);
		if(sl>mid)return qry(ct<<1|1,mid+1,r,sl,sr);
		return max(qry(ct<<1,l,mid,sl,sr),qry(ct<<1|1,mid+1,r,sl,sr));
	}
}tr[3005];
void work2(){
	for(int len=1;len<=n;len++){
		hd=1;tl=0;
		for(int i=1;i<=n;i++){
			while(hd<=tl&&i-q[hd]+1>len)hd++;
			if(i+len-1<=n){
				b[i]=s[i+len-1]-s[i-1];
				while(hd<=tl&&b[i]>=b[q[tl]])tl--;
				q[++tl]=i;
			}
			ff[i][len]=b[q[hd]];
		}
	}
	for(int i=1;i<=n;i++)tr[i].build(i,1,1,n);
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ull res=0;
		for(int i=1;i<=n;i++)
			res^=(1llu*i*tr[i].qry(1,1,n,l,r));
		printf("%llu\n",res);
	}
}
int qmx(int i,int l,int r){
	int k=__lg(r-l+1);
	return max(fmx[i][k][l],fmx[i][k][r-(1<<k)+1]);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		smx[0][i]=s[i];smi[0][i]=s[i-1];
	}
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			smi[j][i]=min(smi[j-1][i],smi[j-1][i+(1<<j-1)]);
			smx[j][i]=max(smx[j-1][i],smx[j-1][i+(1<<j-1)]);
		}
	if(n<=3000){work2();return 0;}
	for(int i=1;i<=n;i++)memset(fmx[i],-0x3f3f3f,sizeof(fmx[i]));
	for(int len=1;len<=32;len++)
		for(int l=1;l+len-1<=n;l++){
			int sum=s[l+len-1]-s[l-1];
			for(int i=l;i<=l+len-1;i++)
				fmx[i][0][len-1]=max(fmx[i][len-1][len-1],sum);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			for(int l=0;l<32;l++)
				fmx[i][j][l]=max(fmx[i][j-1][l],fmx[i][j-1][l+(1<<j-1)]);
	scanf("%d",&Q);
	for(int L,R,tt=1;tt<=Q;tt++){
		scanf("%d%d",&L,&R);
		if(L==R){work1(L);continue;}
		ull res=0;
		if(R<=32){
			for(int i=1;i<=n;i++)
				res^=(1llu*i*qmx(i,L-1,R-1));
			printf("%llu\n",res);continue;
		}
		hd=1;tl=0;
		for(int i=1;i<=n;i++){
			d1[i]=d2[i]=-1e10;
			while(hd<=tl&&i-q[hd]+1>L)hd++;
			if(i+L-1<=n){
				b[i]=qmx(i+L-1,min(n,i+R-1))-s[i-1];
				while(hd<=tl&&b[i]>=b[q[tl]])tl--;
				q[++tl]=i;
			}
			if(hd<=tl)d1[i]=b[q[hd]];
		}
		hd=1;tl=0;
		for(int i=n;i>=1;i--){
			while(hd<=tl&&q[hd]-i+1>L)hd++;
			if(i>=L){
				b[i]=s[i]-qmi(max(1,i-R+1),i-L+1);
				while(hd<=tl&&b[i]>=b[q[tl]])tl--;
				q[++tl]=i;
			}
			if(hd<=tl)d2[i]=b[q[hd]];
			res^=(1llu*i*max(d1[i],d2[i]));
		}
		printf("%llu\n",res);
	}
}