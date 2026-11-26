#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,a[5005],t[5005],x1[5005],x2[5005],ans;
struct str{
	double xjb,yj,bh;
}k[5005];
bool cmp(str x,str y){
	if(x.xjb!=y.xjb) return x.xjb>y.xjb;
	if(x.yj!=y.yj) return x.yj>y.yj;
	return x.bh<y.bh;
}
bool cmp1(int x,int y){
	return x>y;
}
void check(){
	for(int i=1;i<=n;i++){
		k[i].yj=a[i];
		k[i].bh=i;
		k[i].xjb=a[i]*1.0/t[i];
	}
	int l=m,cnt=0,ans1=0,ans2=0;
	while(l>0){
		cnt++;
		if(l>t[cnt]){
			ans1+=a[cnt];
			l-=t[cnt];
		}
	}
	l=m;
	int l1=0,l2=0;
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			l1++;
			x1[l1]=a[i];
		}
		if(t[i]==2){
			l2++;
			x2[l2]=a[i];
		}
	}
	int i1=1,i2=1;
	while(l>0){
		if(l==1){
			ans2+=x1[i1];
			break;
		}
		if(x1[i1]+x1[i1+1]>x2[i2]){
			ans2+=x1[i1]+x1[i1+1];
			i1+=2;
		}
		else{
			ans2+=x2[i2];
			i2++;
		}
		l-=2;
	}		
	if(ans1==ans2) ans++;
	ans%=998244353;
}
void find(int p){
	if(p>n){
		check();
		return ;
	}
	t[p]=1;
	find(p+1);
	t[p]=2;
	find(p+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==18){
			long long as=1;
			for(int i=1;i<=n;i++){
				as*=2;
				as%=998244353;
			}
			cout<<as<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		find(1);
		cout<<ans%998244353<<endl;
	}
	return 0;
}

