#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,s,ans,sum,minn,f,xa,xb;
struct node{
	long long a,b,c;
}x[1000005];
bool cmp(node l,node r){
	return l.a<r.a;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	minn=2e9+1;
	scanf("%lld%lld",&n,&m);
	mm=m;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i].a,&x[i].b);
		x[i].c=x[i].a+x[i].b;
		if(x[i].c<minn){
			minn=x[i].c;
			f=i;
		}
		else if(x[i].c==minn){
			if(x[i].a<x[f].a)f=i;
		}
	}
	xa=x[f].a;
	xb=x[f].b;
	sort(x+1,x+n+1,cmp);
	for(int i=1;i<=n;i++){
		//printf("%lld %lld\n",x[i].a,x[i].b);
		if(xa==x[i].a&&x[i].b==xb){
			f=i;
			break;
		}
	}
	//printf("%lld %lld %lld\n",f,x[f].a,x[f].b);
	//printf("\n\n");
	for(int i=1;i<f;i++){
		m-=x[i].a;
		ans++;
	}
	//printf("%lld %lld %lld %lld\n",x[f].a,x[f].b,m,ans);
	minn=x[f].a+x[f].b;
	ans=ans+(m/minn)*2;
	m%=minn;
	if(m>=xa)ans++,m-=xa;
	for(int i=f+1;i<=n;i++){
		if(m>=x[i].a){
			m-=x[i].a;
			ans++;
			if(x[i].b<=x[i+1].a&&m>=x[i].b){
				m-=x[i].b;
				ans++;
				ans=ans+(m/x[i].c)*2;
				m%=x[i].c;
			}
		}
		if(mm<x[i].a){
			break;
		}
	}
	//printf("%lld %lld %lld %lld\n",x[f].a,x[f].b,m,ans);
	sum=(mm/x[f].c)*2;
	mm%=x[f].c;
	//printf("mm %lld %lld\n",mm,sum);
	for(int i=1;i<=n;i++){
		if(mm>=x[i].a){
			mm-=x[i].a;
			sum++;
			if(x[i].b<=x[i+1].a&&mm>=x[i].b){
				mm-=x[i].b;
				sum++;
				sum=sum+(mm/x[i].c)*2;
				mm%=x[i].c;
			}
		}
		if(mm<x[i].a){
			break;
		}
	}
	ans=max(ans,sum);
	printf("%lld\n",ans);
	return 0;
}
