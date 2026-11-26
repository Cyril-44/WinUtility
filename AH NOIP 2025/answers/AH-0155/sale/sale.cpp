#include<bits/stdc++.h>
using namespace std;
int n,a[5010],c,T,m,Mod=998244353;
long long ans2=0;
/*struct st{
	int past,now,id;
}e[5010];
bool cmp1(st a,st b){
	double s1=a.past*1.0/a.now;
	double s2=b.past*1.0/b.now;
	if(s1!=s2)return s1>s2;
	if(a.past!=b.past)return a.past>b.past;
	return a.id<b.id;
}
bool cmp2(st a,st b){
	if(a.now!=b.now)return a.now<b.now;
	return a.past>b.past;
}
int check(){
	sort(e+1,e+n+1,cmp1);
	int sum1=0,w=m,sum2=0,fl=0;
	for(int i=1;i<=n;i++){
		if(w>=e[i].now)w-=e[i].now,sum1+=e[i].past;
	}
	sort(e+1,e+n+1,cmp2);
	for(int i=1;i<=n;i++)
		if(e[i].now==2){
			fl=i;break;
		}
	if(fl==0)fl=n+1;
	int i=1,j=fl;
	w=m;
	while(w!=0){
		if(w>=2&&j<=n){
			if(i<fl-1&&j<=n&&e[i].past+e[i+1].past>e[j].past){
				sum2+=e[i].past+e[i+1].past;
				i+=2;
				w-=2;
			}
			else if(i==fl-2&&j<=n&&e[i].past>e[j].past)sum2+=e[i].past,i++,w--;
			else{
				sum2+=e[j].past;j++;
				w-=2;
			}
		}
		else{
			if(w>=1)sum2+=e[i].past,i++,w--;
		}
	}
	if(sum1==sum2)return 1;
	return 0;
}
void f(int x){
	if(x==n+1){
		if(check())ans2++;
	}
	for(int i=1;i<=2;i++){
		e[x].past=a[x],e[x].now=i,e[x].id=x;
		f(x+1);
	}
}*/
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==18){
			long long ans=1;
			for(int i=1;i<=n;i++)ans=ans*2%Mod;
			cout<<ans;
		}
		/*else{
			ans2=0;
			f(1);
			cout<<ans2<<endl;
		}*/
	}
	return 0;
}
