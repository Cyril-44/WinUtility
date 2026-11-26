#include<bits/stdc++.h>
using namespace std;
int n,p,q,flag=1,minn=1111111111,mihe=2000000099,hehe,pp,qq,flg=1,midex,lt,rt;
long long m,ans;
struct st{
	int x,y,xh;
}a[111111];
bool cmp(st xxx,st yyy){
	return xxx.x<yyy.x;
}
int cnt(int kp,int kq,int kfg){
	int kans=0;
	for(;;){
		if(kfg==1){
			if(m>=kp){
				m-=kp;
				kans++;
				kfg=2;
			}else{
				break;
			}
		}
		if(kfg==2){
			if(m>=kq){
				m-=kq;
				kans++;
				kfg=1;
			}else{
				break;
			}
		}
	}
	return kans;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		int fg=1,ans=0;
		cin>>p>>q;
		for(;;){
			if(fg==1){
				if(m>=p){
					m-=p;
					ans++;
					fg=2;
				}else{
					cout<<ans;
					break;
				}
			}
			if(fg==2){
				if(m>q){
					m-=q;
					ans++;
					fg=1;
				}else{
					cout<<ans;
					break;
				}
			}
		}
		return 0;
	}
	if(n==2){
		cin>>p>>q>>pp>>qq;
		int h1=p+q,h2=pp+qq;
		if(h1<h2||(h1==h2&&pp>=p)){
			if(pp<=h1/2){
				if(m>=pp){
					m-=pp;
					ans++;
				}else{
					cout<<ans;
					return 0;
				}
			}
			int fg=1;
			for(;;){
				if(fg==1){
					if(m>=p){
						m-=p;
						ans++;
						fg=2;
					}else{
						cout<<ans;
						break;
					}
				}
				if(fg==2){
					if(m>=q){
						m-=q;
						ans++;
						fg=1;
					}else{
						cout<<ans;
						break;
					}
				}
			}
		}
		if(h1>h2||(h1==h2&&pp<p)){
			if(p<=h2/2){
				if(m>=p){
					m-=p;
					ans++;
				}else{
					cout<<ans;
					return 0;
				}
			}
			int fg=1;
			for(;;){
				if(fg==1){
					if(m>=pp){
						m-=pp;
						ans++;
						fg=2;
					}else{
						cout<<ans;
						break;
					}
				}
				if(fg==2){
					if(m>=qq){
						m-=qq;
						ans++;
						fg=1;
					}else{
						cout<<ans;
						break;
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){	
		cin>>a[i].x>>a[i].y;
		if(a[i].x!=a[i].y)flag=0;
		a[i].xh=i;
		hehe=a[i].x+a[i].y;
		if(mihe>hehe||(mihe==hehe&&a[i].x<=a[midex].x)){
			mihe=hehe;
			midex=a[i].xh;
		}
		
	}
	
	if(flag){
		for(int i=1;i<=n;i++){
			minn=min(minn,a[i].x);
		}
		cout<<m/minn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	
	if(n!=1&&n!=2){
		for(int i=1;i<=n;i++){
			
			if(a[i].x<=mihe/2){
				if(m>=a[i].x){
					m-=a[i].x;
					ans++;
					if(a[i].xh==midex){
						flg=2;
					}
				}else{
					cout<<ans;
					break;
				}
			}
			else break;
		}
		for(int i=1;i<=n;i++){
			if(a[i].xh==midex){
				lt=a[i].x;
				rt=a[i].y;
			}
		}
		ans+=cnt(lt,rt,flg);
		cout<<ans;	
	}
	return 0;
}
