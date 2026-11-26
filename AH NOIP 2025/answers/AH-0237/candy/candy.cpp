#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct S{
	long long xi,yi;
	long long suma1,suma2;
}a[N];
int cmp(const S &x,const S &y){
	return x.xi<y.xi;
}
int cmp1(const S &x,const S &y){
	return x.xi<y.xi;
	if(x.xi==y.xi) return x.yi<y.yi;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	int f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].xi>>a[i].yi;
		a[i].suma1=a[i].xi;
		a[i].suma2=a[i].xi+a[i].yi;
		if(a[i].xi!=a[i].yi) f=0;
	}
	sort(a+1,a+n+1,cmp);
	if(n==1){
		int cnt=0;
		if(m>=a[1].suma2) cnt=(m/a[1].suma2)*2;
		m=m%a[1].suma2;
		if(m>=a[1].suma1) cnt++; 
		cout<<cnt;
	}
	else if(n==2){
		int k1,k2,k3,k4,k5,k6;
		int cnt=0;
		k1=a[1].xi;//...
		k2=a[1].yi;
		k3=a[2].xi;//...
		k4=a[2].yi;
		k5=k1+k2,k6=k3+k4;
		if(m>=min(k5,k6)) cnt=(m/min(k5,k6))*2;
		m%=min(k5,k6);
		if(m>=min(k1,k3)) {
			m-=min(k1,k3);
			cnt++;
		}
		if(m>=max(k1,k3)){
			m-=max(k1,k3);
			cnt++;
		}
		cout<<cnt;		
	}
	else if(f==1){
		long long cnt=0;
		cnt=m/a[1].xi;
		cout<<cnt;
	}else{
		sort(a+1,a+n+1,cmp1);
		int i=1;
		long long cnt=0;
		while(m>0){
			if(m>=a[i].xi){
				m-=a[i].xi;
				cnt++;
				if(m>=a[i].yi){
					if(a[i].yi<=a[i+1].xi+a[i].xi){
						m-=a[i].yi;
						cnt++;
					}else if(a[i].yi>a[i+1].xi+a[i].xi){
						m-=a[i+1].xi;
						cnt++;
					}
				}
				else if(m<a[i].yi){
					i++;
				}
			}
			else break;
		}
		cout<<cnt-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
