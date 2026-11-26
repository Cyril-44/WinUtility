#include<bits/stdc++.h>
#define int long long
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
const int N=5e3+10,MOD=998244353;
int c,t;
int n,m,a[N],jc[N]={1},ivjc[N]={1};
pair<int,int> b[N];
int C(int xx,int yy){
	if(yy>xx||yy<0)return 0;
	return jc[xx]*ivjc[yy]%MOD*ivjc[xx-yy]%MOD;
}
bool cmp(int x,int y){return x>y;}
int kpw(int x,int y){
	if(y<0)return 1;
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%MOD;
		y>>=1;x=x*x%MOD;
	}
	return ans;
}
bool cp(pair<int,int> x,pair<int,int> y){
	if(x.first!=y.first)return x.first>y.first;
	return x.second>y.second;
}
void work(){
	cin>>n>>m;
	int ans=kpw(2,n);
	int val=0;
	forr(i,1,n){
		cin>>a[i],a[i]<<=1;
		if(val==0)val=a[i];
		else if(val!=-1&&val!=a[i])val=-1;
	}
	if(val>0||m==n+n-1){
		cout<<ans<<endl;return;
	}
	sort(a+1,a+1+n,cmp);
	if(c==7||c==8||c==9||c==14||c==15){
		int s=a[1]/2;
		int l=1,r=n+1;
		while(l<r){
			int mid=((l+r)>>1);
			if(a[mid]>s)l=mid+1;
			else r=mid;
		}
		
		forr(i,2,l-1){
			forr(j,l,n+1){
				if(a[i]+a[j]<a[1])ans-=kpw(2,n-j);
			}
		}
		ans%=MOD;ans+=MOD;ans%=MOD;
		cout<<ans<<endl;
		forr(i,1,n)a[i]=0;
		return ;
	}
	if(c==11||c==12||c==10||c==19||c==20||c==0){
		forr(i,1,n){
			if(n-i>=m||(n+i)<=m)continue;
			if((m-(n-i))%2==0)continue;
			int s1=(m-(n-i)+1)/2;
			ans-=C(n,i);
			ans+=C(n-(i-s1+1),s1-1);
			ans%=MOD;ans+=MOD;ans%=MOD;
		}
		cout<<ans<<endl;return;
	}
	if(m==2*n-2){
		if(a[n]*2>a[n-1]&&a[n]!=a[n-1])ans--;
		ans+=MOD;ans%=MOD;
		cout<<ans<<endl;
		return ;
	}
	//cout<<ans<<' ';
	forr(i,0,(1<<n)-1){
		forr(j,0,n-1){
			if(i&(1<<j)){
				b[j+1]={a[j+1]/2,a[j+1]};
			}else{
				b[j+1]={a[j+1],a[j+1]};
			}
		}
		sort(b+1,b+1+n,cp);
		int tm=m;
		forr(j,1,n){
			int cc=b[j].second/b[j].first;
			if(tm>=cc)tm-=cc;
			else{
				if(cc==2&&tm==1){
					int pl1=0,vv=0;
					roff(k,j-1,1){
						if(b[k].second==b[k].first){
							pl1=k,vv+=b[k].second;break;
						}
					}
					if(!pl1)break;
					forr(k,j+1,n){
						if(b[k].first==b[k].second){
							vv+=b[k].second;break;
						}
					}
					if(vv<b[j].second){
						ans--;
					}
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	forr(i,1,5000)jc[i]=jc[i-1]*i%MOD;
	ivjc[5000]=kpw(jc[5000],MOD-2);
	roff(i,4999,1)ivjc[i]=ivjc[i+1]*(i+1)%MOD;
	while(t--)work();
	return 0;
}
