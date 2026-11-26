#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e3+5;
int bh,team,n,m,a[N];
int read(){
	int num=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')fh*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*fh;
}
int ans;
void dfs(int id,int pre){
	if(id>=n){
		ans=(ans+1)%mod;
		return;
	}
	id++;
	if(pre<=a[id])dfs(id,a[id]);
	if(pre<=a[id]/2)dfs(id,a[id]/2);
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10){
		write(x/10);
		putchar((x%10)+'0');
	}else{
		putchar(x+'0');
	}
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bh=read(),team=read();
	while(team--){
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		if(m==1){
			ans=(1<<(n-1))%mod;
		}else if(m==2){
			if(a[n-2]<a[n-1]/2){
				ans=(1<<(n-1))%mod;
			}else{
				ans=(1<<(n-1))%mod;
				for(int i=n-2;i>=1;i--){
					if(a[i]>=a[n-1]/2){
						ans=(ans-(1<<i)+mod)%mod;
					}else break;
				}
			}
		}else if(m<=26){
			dfs(1,a[1]);
			dfs(1,a[1]/2);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
