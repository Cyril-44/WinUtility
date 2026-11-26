#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct st{
	int x,y,sum;
}a[100005];
struct st2{
	int id,val;
}b[100005];
struct st3{
	int val,w;
}c[200005];

int n,cnt1=0,cnt2=0;
long long m,ans=0,ans1,ans2,m1;

bool cmp(st x,st y){
	return x.sum<y.sum;
}
bool cmp1(st x,st y){
	return x.y<y.y;
}
bool cmp2(st x,st y){
	return x.x<y.x;
}
bool cmpb(st2 x,st2 y){
	return x.val<y.val;
}

long long f[7000000],cnt=0;
bool flag[100005];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		a[i].sum=a[i].x+a[i].y;
		if(a[i].x==a[i].y) cnt1++;
		if(a[i].x>=a[i].y) cnt2++;
	}
	sort(a+1,a+n+1,cmp);
	if(cnt1==n){
		ans=m/(a[1].x*1ll);
		cout<<ans<<endl;
		return 0;
	}
	if(m<1e7){
		for(int i=1;i<=n;i++){
			c[++cnt]={1,a[i].x};
			c[++cnt]={2,a[i].sum};
		}
		
		for(int i=1;i<=cnt;i++){
			if(i%2==1){
				for(int j=m;j>=c[i].w;j--){
					f[j]=max(f[j],f[j-c[i].w]+c[i].val);
					ans=max(ans,f[j]);
				}	
			}else{
				for(int j=c[i].w;j<=m;j++){
					f[j]=max(f[j],f[j-c[i].w]+c[i].val);
					ans=max(ans,f[j]);
				}	
			}
		 }
		 cout<<ans<<endl;
		 return 0;
	}
	if(cnt2==n){
		ans=m/(a[1].sum*1ll)*2;
		m-=m/(a[1].sum*1ll)*a[1].sum*1ll;
		if(m>a[1].x) ans++;
		cout<<ans<<endl;
		return 0;
	}
	ans1=m/a[1].sum*2*1ll;
	m1=m-m/a[1].sum*a[1].sum;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++) b[i].val=a[i].x,b[i].id=i;
	while(m1){
		if(m1<b[1].val) break;
		m1-=b[1].val;
		if(flag[b[1].id]==0){
			 b[1].val=a[b[1].id].y;
			 flag[b[1].id]=1;
		}else{
			 b[1].val=a[b[1].id].x;
			 flag[b[1].id]=0;
		}
		ans1++;
		sort(b+1,b+n+1,cmpb);
	}
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++) b[i].val=a[i].x,b[i].id=i;
	while(m){
		if(m<b[1].val) break;
		m-=b[1].val;
		if(flag[b[1].id]==0){
			 b[1].val=a[b[1].id].y;
			 flag[b[1].id]=1;
		}else{
			 b[1].val=a[b[1].id].x;
			 flag[b[1].id]=0;
		}
		ans++;
		sort(b+1,b+n+1,cmpb);
	}
	cout<<max(ans,ans1)<<endl;
}
