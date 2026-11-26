#include<bits/stdc++.h>
using namespace std;
int n,w;
long long m,mm,ans,ans1,anss,t1,t2,mi=2*1000000010,mt,pt,mx,my,wt;
struct node{
	long long x,y;
}a[100010];
long long p[100010];
bool cmp(node p,node q){
	if(p.x==q.x)return p.y<q.y;
	return p.x<q.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	mm=m;
//	cout<<m<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	//	mi=min(mi,(long long int)a[i].x+a[i].y);
		if(mi>a[i].x+a[i].y){
			mi=a[i].x+a[i].y,mt=i;
			mx=a[i].x,my=a[i].y;
		}
	}
	ans1=(m/(mx+my))*2;
	if(m%(mx+my)>=mx)ans1++;
	a[mt].x=1000000010,a[mt].y=1000000010;
	sort(a+1,a+1+n,cmp);
	//for(int i=1;i<=n;i++){
	//	cout<<a[i].x<<' '<<a[i].y<<'\n';
	//}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		t1+=a[i].x;
		if(a[i].x+a[i+1].x>=mi){
			w=i;
			break;
		}
	}
	ans+=w;
//	cout<<w<<' '<<t1<<endl;
	m-=t1;
//	cout<<mi<<' '<<mt<<' '<<m<<' '<<ans<<'\n';
	ans+=(m/(mx+my))*2;
	m%=(mx+my);
	p[++wt]=mx;
//	cout<<m<<'\n'<<ans<<'\n';
	for(int i=1;i<=w;i++){
		p[++wt]=a[i].y;
	}
	for(int i=w+1;i<=n;i++){
		p[++wt]=a[i].x;
	}
	sort(p+1,p+1+wt);
	for(int i=1;i<=wt;i++){
		if(m>=p[i]){
			ans++,m-=p[i];
		}
	}
	anss=max(ans,ans1);
	ans=0,w++,wt=0,t1+=a[w].x,m=mm;
	ans+=w;
	m-=t1;
	ans+=(m/(mx+my))*2;
	m%=(mx+my);
	p[++wt]=mx;
//	cout<<m<<'\n'<<ans<<'\n';
	for(int i=1;i<=w;i++){
		p[++wt]=a[i].y;
	}
	for(int i=w+1;i<=n;i++){
		p[++wt]=a[i].x;
	}
	sort(p+1,p+1+wt);
	for(int i=1;i<=wt;i++){
		if(m>=p[i]){
			ans++,m-=p[i];
		}
	}
	anss=max(ans,anss);
	ans=0,w-=2,wt=0,t1-=a[w+1].x+a[w+2].x,m=mm;
	ans+=w;
	m-=t1;
	ans+=(m/(mx+my))*2;
	m%=(mx+my);
	p[++wt]=mx;
//	cout<<m<<'\n'<<ans<<'\n';
	for(int i=1;i<=w;i++){
		p[++wt]=a[i].y;
	}
	for(int i=w+1;i<=n;i++){
		p[++wt]=a[i].x;
	}
	sort(p+1,p+1+wt);
	for(int i=1;i<=wt;i++){
		if(m>=p[i]){
			ans++,m-=p[i];
		}
	}
	anss=max(ans,anss);
	cout<<anss;
	return 0;
}
