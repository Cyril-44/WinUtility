#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
void in(int &x){
	int f=1;char c=getchar();x=0;
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),f=-1;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,a[100005],b[100005],s[100005],L[100005],R[100005];
int d[100005],q[100005],p[155][10005];
ull res[100005];
void solve(){
	memset(p,-0x3f,sizeof p);
	for(int k=1;k<=n;k++){
		for(int j=1;j+k-1<=n;j++)d[j]=-s[j-1]+s[j+k-1];
    	int hd=1,ed=0;
    	for(int i=1;i<=n;i++){
    	    while(hd<=ed&&q[hd]<=i-k)hd++;
    	    if(i+k-1<=n){while(hd<=ed&&d[q[ed]]<d[i])ed--;q[++ed]=i;}
    	    int mw=d[q[hd]];
    	    for(int o=1;o<=m;o++)if(L[o]<=k&&k<=R[o])p[o][i]=max(p[o][i],mw);
    	}
	}
	for(int o=1;o<=m;o++){
		for(int i=1;i<=n;i++){
			ull cur=p[o][i];cur*=i;
			res[o]^=cur;
		}
	}
    for(int i=1;i<=m;i++)printf("%llu\n",res[i]);
}
void solve2(){
	for(int o=1;o<=m;o++){
    	if(L[o]==R[o]){
    		int k=L[o];
    		for(int j=1;j+k-1<=n;j++)d[j]=-s[j-1]+s[j+k-1];
    		int hd=1,ed=0;
    	    for(int i=1;i<=n;i++){
    	    	while(hd<=ed&&q[hd]<=i-k)hd++;
    	    	if(i+k-1<=n){while(hd<=ed&&d[q[ed]]<d[i])ed--;q[++ed]=i;}
    	    	ull cur=d[q[hd]];cur*=i;res[o]^=cur;
    	    }
    	}
    }
    for(int i=1;i<=m;i++)printf("%llu\n",res[i]);
}
int mx[50005][35],w[35][35];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	in(n);
	for(int i=1;i<=n;i++)in(a[i]),s[i]=s[i-1]+a[i];
	in(m);
    for(int i=1;i<=m;i++)in(L[i]),in(R[i]);
    if(n<=10000){solve();return 0;}
    bool ok=1;
    for(int i=1;i<=m;i++)ok&=(L[i]==R[i]);
    if(ok){solve2();return 0;}
    memset(w,-0x3f,sizeof w);
    memset(mx,-0x3f,sizeof mx);
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n&&j<=i+31;j++){
    		int k=j-i+1;
    		for(int o=i;o<=j;o++)mx[o][k]=max(mx[o][k],s[j]-s[i-1]);
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int x=1;x<=32;x++)for(int y=x;y<=32;y++){w[x][y]=max(mx[i][y],w[x][y-1]);}
    	for(int o=1;o<=m;o++){
    		ull cur=w[L[o]][R[o]];
    		cur*=i;res[o]^=cur;
    	}
    }
    for(int i=1;i<=m;i++)printf("%llu\n",res[i]);
}