#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,ans,w;
int s[N],dd[N];
struct node{int x,y,tot,id;}a[N],b[N];
bool cmp1(node a,node b){return a.tot<b.tot;}
bool cmp2(node a,node b){return a.x<b.x;}
signed main(){
	//freopen("candy7.in","r",stdin);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].tot=a[i].x+a[i].y;
		a[i].id=i;
		b[i].x=a[i].y;
	}
	sort(a+1,a+1+n,cmp1);
	int bj=a[1].id,xx=a[1].tot,aa=a[1].x,bb=a[1].y;
	sort(a+1,a+1+n,cmp2);
	int now=0,nowcnt=0,flag=0,nowm=0,mamba=0;
	int nowid=1;
	for(int i=1;i<=n;i++){
		nowcnt+=a[i].x;
		now++;
		if(now==2){
			if(nowcnt<=xx&&nowm+nowcnt<=m){
				nowm+=nowcnt;
				ans+=2;
				dd[a[i].id]=1;
				dd[a[i-1].id]=1;
				mamba+=2;
			}else{
				break;
			}
			nowcnt=0;
			now=0;
		}
	}
	m-=nowm;
	if(m>xx){
		ans+=m/xx*2;
		m%=xx;
	}
	
	for(int i=1;i<=n;i++){
		if(dd[i]!=1){
			b[i].x=a[i].x;
		}
	}
	sort(b+1,b+1+n,cmp2);
	if(mamba!=n&&m>b[1].x){
		m-=b[1].x;
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
