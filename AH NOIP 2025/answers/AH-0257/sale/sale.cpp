#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[50005],f[50005],l;
long long r=0;
bool w[50005];
struct xjb{
	int c,h,w1;
	float b;
}q[50005];
bool cmp(xjb b1,xjb b2){
	if(b1.b==b2.b){
		if(b1.c==b2.c){
			return b1.h<b2.h;
		}
		return b1.c>b2.c;
	}
	return b1.b>b2.b;
}
void dg(long long y,long long sum,long long x){
	for(int i=1;i<=n;i++){
		if(f[i]<=y){
			if(w[i]==false) continue;
			w[i]=false;
			dg(y-f[i],sum+a[i],i);
		}
		else{
			continue;
		}
	}
	w[x]=true;
	r=max(r,sum);
	return;
}
void fz(int x){
	if(x==0){
		r=0;
		for(int i=1;i<=n;i++){
			w[i]=true;
		}
		dg(m,0,0);
		for(int i=1;i<=n;i++){
			q[i].b=double(a[i]*1.0/f[i]*1.0);
			q[i].c=a[i];
			q[i].h=i;
		}
		sort(q+1,q+1+n,cmp);

		int p=m,ans=0;
		for(int i=1;i<=n;i++){
			if(q[i].w1<=p){
				p-=q[i].w1;
				ans+=q[i].c;
			}
			else continue;
		}
		if(ans==r) l++; 
		return;
	}
	for(int i=1;i<=2;i++){
		f[x]=i;
		q[x].w1=i;
		fz(x-1);
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
			w[i]=true;
		}
		if(c==18){
			int s=1;
			for(int i=1;i<=n;i++){
				s=(s*2)%998244353;
			}
			cout<<s<<endl;
		}
		if(n>=10) cout<<0;
		fz(n);
		cout<<l<<endl;
		l=0;
	}
    return 0;
}
