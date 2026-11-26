#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 5003
int n,m,c,t;
struct node{
	int id,val,cos;
}num[N];
long long dp[N*2],ans;
long long ksm(long long a,int b){
	long long tot=a,ans=1;
	while(b){
		if(b&1){
			ans=ans*tot%mod;
		}
		tot=tot*tot%mod;
		b/=2;
	}
	return ans;
}
bool cmp(node x,node y){
	if(x.val*y.cos==y.val*x.cos){
		return x.val>y.val;
	}
	return x.val*y.cos>y.val*x.cos;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
void deal(){
	for(int i=1;i<=m;i++){
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			if(j>=num[i].cos){
				dp[j]=max(dp[j],dp[j-num[i].cos]+num[i].val);
			}
		}
	}
//	cout<<dp[m]<<endl;
	sort(num+1,num+n+1,cmp);
	int w=m;
	long long tot=0;
	for(int i=1;i<=n;i++){
		if(w>=num[i].cos){
			w-=num[i].cos;
			tot+=num[i].val;
		}
	}
	if(tot==dp[m]){
		ans=(ans+1)%mod;
	}
	sort(num+1,num+n+1,cmp2);
}
void dfs(int now){
	if(now==n+1){
		deal();
		return ;
	}
	num[now].cos=1;
	dfs(now+1);
	num[now].cos=2;
	dfs(now+1);
}
int in(){ 
	int tot=0,id=1;
	char c=getchar();
	while('0'>c||'9'<c){
		if(c=='-'){
			id=-1;
		}
		c=getchar();
	}
	while('0'<=c&&'9'>=c){
		tot=tot*10+c-'0';
		c=getchar();
	}
	return tot*id;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	c=in();
	t=in();
	int flag=1;
	while(t--){
		n=in(),m=in();
		flag=1;
		for(int i=1;i<=n;i++){
			num[i].val=in();
			num[i].id=i;
			if(num[i].val!=num[i-1].val){
				flag=0;
			}
		}
		if(flag){
			printf("%lld\n",ksm(2,n));
		}
		else{
			ans=0;
			dfs(1);
			printf("%lld\n",ans);
		}
	}


	return 0;
}
/*
0 2
5 5
483903342 335678433 241951671 241951671 251607302
*/
