#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
	long long c;
	bool f=0;
}d[100010];
long long n,m,minn=1e18+10,minj,num,tt,ans,kk,tt1,mm=1;
int l[100010];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].b;
		d[i].c=d[i].b+d[i].a;
		if(minn>d[i].c){
			minn=d[i].c;
			minj=i;
		}
		if(minn==d[i].c&&d[i].a>d[minj].a){
			minj=i;
		}
	}
	d[minj].f=1;
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(d[i].f==0){
			num+=d[i].a;
			tt++;
			kk++;
		}
		if(num>=minn){
			if(kk-1<2){
				tt=tt1;
				break;
			}
			else{
				kk=1;
			}
			tt1=i-1;
		}
	}
	if(tt>=2){
		int c;
		for(int i=1;i<=n;i++){
			if(d[i].f==0){
				tt--;
				m-=d[i].a;
				ans++;
				l[i]=d[i].b;
			}
			else l[i]=d[i].a;
			if(tt==0){
				c=i;
				break;
			}
		}
		for(int i=c+1;i<=n;i++){
			l[i]=d[i].a;
		}

	}
	else {
		for(int i=1;i<=n;i++){
			l[i]=d[i].a;
		}
	}
	ans+=m/minn*2;
	m=m%minn;
	sort(l+1,l+n+1);
	int k=0;
	while(m-l[k+1]>=0){
		ans++;
		m-=l[k+1];
		k++;
	}
	cout<<ans;
	return 0;
}
//!noip@Nov29,2025:dream
/*
5 45
1 7
2 6
3 9
4 10
5 6

 */
