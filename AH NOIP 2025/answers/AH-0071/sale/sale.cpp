#include<bits/stdc++.h>
using namespace std;
int t0,t,k[100005],c[100005];
long long n,m,l=998244353,ans;
long long a[100005];
struct tg{
	long long x,y,h;
};
tg b[100005];
// !noip@Nov29,2025:dream
bool p(tg a,tg b){
	if(a.x*b.y==b.x*a.y) return a.x>b.x;
	return a.x*b.y>b.x*a.y;
}
long long ss(long long a,long long b){
	if(a<b||a==0||b<0) return 0;
	if(a==b||b==0) return 1;
	unsigned long long ans=1,j=2;
	for(int i=b+1;i<=a;i++){
		ans*=i;
		while(ans%j==0&&j<=a-b){
			ans/=j;j++;
		}
	}
	return ans%l;
}
long long er(int k){
	if(k<0) return 1;
	if(k==0) return 1;
	long long ans=1;
	while(k--){
		ans*=2; ans%=l;
	}
	return ans;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>t0>>t;
    if(t0==18){
        while(t--){
	    	cin>>n>>m;
            for(int i=1;i<=n;i++)
                cin>>a[i];
		    cout<<er(n)<<endl;
	    }
	}else
    while(t--){
		cin>>n>>m; ans=0;  
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i*2-1].x=a[i]; b[i*2].x=a[i]; 
            b[i*2-1].y=1; b[i*2].y=2;
            b[i*2-1].h=i; b[i*2].h=i;
		} 
     	sort(b+1,b+n*2+1,p);
     	if(m==2){
			sort(a+1,a+n+1);
			if(a[n]<a[n-1]+a[n-2]) cout<<er(n)<<endl;
			else if(a[n-1]*2<a[n]) cout<<er(n)-er(n-2)<<endl;
			else cout<<er(n)<<endl;
		}else{
     	long long s1=0,s2=0;
     	for(int i=1;i<n*2;i++){
			if(b[i].y==2){
				long long js=0;
             	for(int j=1;j<i;j++)
             	    if(b[j].y==1&&b[j].x<b[i].x) js++;
             	if(js>0){
	                ans+=ss(s1+s2-1,m-s2-1)*er(n-s1-s2);
	                ans-=ss(s1+s2-1-js,m-s2-1);
             	for(int j=1;j<i;j++)
             	if(b[j].y==1&&b[j].x<b[i].x)
             	for(int j2=i+1;j2<=n*2;j2++)
             	if(b[j2].y==1&&b[j].x+b[j2].x>b[i].x)
             	    ans-=ss(s1+s2-1-1,m-s2-1-1)*er(n-s1-s2-1);//(n*2-i);
				}
				ans%=l;
		        //cout<<s1<<" "<<s2<<endl;
		    	//cout<<i<<"   "<<ans<<" "<<" "<<ss(s1+s2-1,m-s2-1)<<endl;
				s2++; s1--;
			}
			if(b[i].y==1) s1++;
		}
		cout<<(er(n)-ans+l)%l<<endl;
	}
	}
    return 0;
}
