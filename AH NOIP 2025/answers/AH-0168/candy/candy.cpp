#include <bits/stdc++.h>
using namespace std;
struct node{
	long long b;
	long long c;
	long long s;
	int id;
}a[200005];
bool cmp(node a1,node a2){
	return a1.s<a2.s;
}
bool cmpp(node a1,node a2){
	return a1.b<a2.b;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].b,&a[i].c);
		a[i].s=a[i].b+a[i].c;
		a[i].id=i;
	}
	int idd;
	long long idc,ids,idb;
	long long ans=0,sum=-1;
	sort(a+1,a+n+1,cmp);
	idd=a[1].id;
	idb=a[1].b;
	idc=a[1].c;
	ids=a[1].s;
	long long p,pp;
	p=m/a[1].s;
	ans+=(p*2);
	pp=m-p*a[1].s;
	m=pp;
	bool flag=0;
	if(m>=a[1].b){
		m-=a[1].b;
		ans++;
		flag=1;
	}
	sort(a+1,a+n+1,cmpp);
	for(int i=1;i<=n;i++){
		//cout<<ans<<" "<<endl;
		if(a[i].id!=idd){
			if(m>=a[i].b){
				m-=a[i].b;
				if(sum==-1){
					ans++;
				}
				sum=-1;
			}
			else if(flag==0){
				if(sum!=-1){
					break;
				}
				if(idc>=a[i].b&&p>0){
					//cout<<idc<<endl;
					flag=1;
					m=m-a[i].b+idc;
				}
				else if(m+ids>=a[i].b&&p>0){
					sum=0;
					m=m-a[i].b+ids;
					p--;
				}
				else{
					break;
				}
			}
			else{
				if(sum!=-1){
					break;
				}
				if(m+idb>=a[i].b){
					m=m-a[i].b+idb;
					flag=0;
					p--;	
				}
				else if(m+ids>=a[i].b&&p>1){
					sum=0;
					m=m-a[i].b+ids;
					p--;
				}
				else{
					break;
				}
			}
		}
	}
	if(flag==0){
		if(m>=idb){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
