#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
struct price{
	int ji,ou;
	int tot;
	bool wc;
};
price kd[100010];
int pre[100010],t=1;
bool cmp(price a,price b){
	return a.tot<b.tot;
}
bool cp(price a,price b){
	return a.ji<b.ji;
}
bool c(price a,price b){
	return a.ou<b.ou;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		kd[i].ji=read();
		kd[i].ou=read();
		kd[i].tot=kd[i].ji+kd[i].ou;
		kd[i].wc=0;
	}
	int ans=0;
	sort(kd+1,kd+n+1,cmp);
	sort(kd+2,kd+n+1,cp);
	//cout<<kd[1].ji<<" "<<kd[1].ou<<endl;
	for(int i=2;i<=n;i++){
		if(2*kd[i].ji<kd[1].tot&&m>=kd[i].ji&&kd[i].ji<kd[1].ji){
			ans++;
			m-=kd[i].ji;
			kd[i].wc=1;
			pre[t]=kd[i].ji;
			t++;
			//cout<<m<<" "<<ans<<" "<<kd[i].ji<<" "<<kd[i].ou<<endl;
		}
	}
	/*if(m>=kd[1].ji){
		ans+=1;
		m-=kd[1].ji;
	}
	sort(kd+2,kd+n+1,c);
	for(int i=2;i<=n;i++){
		if(m>=kd[i].ji&&kd[i].ji<kd[1].ou&&(!kd[i].wc)){
			ans++;
			m-=kd[i].ji;
			kd[i].wc=1;
			//cout<<m<<" "<<ans<<" "<<kd[i].ji<<endl;
		}
	}
	if(m>=kd[1].ou){
		ans+=1;
		m-=kd[1].ou;
	}*/
	ans+=2*(m/kd[1].tot);
	m=m-(m/kd[1].tot)*kd[1].tot;
	price a;
	a.ji=kd[1].ji;
	a.ou=kd[1].ou;
	a.tot=kd[1].tot;
	a.wc=kd[1].wc;
	sort(kd+1,kd+n+1,cp);
	for(int i=1;i<=n;i++){
		if(!kd[i].wc){
			if(kd[i].ji<=m){
				ans++;
				m-=kd[i].ji;
				kd[i].wc=1;
			}
		}
		if(m<=0) break;
	}
	for(int i=t-1;i>0;i--){
		if(m+pre[i]>=a.tot) {
			m=m+pre[i]-a.tot;
			ans++;
		}
	}
	/*cout<<m<<endl;
	for(int i=1;i<=n;i++){
		cout<<kd[i].ji<<" ";
		cout<<kd[i].ou<<endl;
	}*/
	cout<<ans;
	return 0;
}
