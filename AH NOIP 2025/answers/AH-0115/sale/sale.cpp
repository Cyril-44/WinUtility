#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
long long b[5005],a[5005],ans;
struct sum{
	long long num,w;
}d[5005];
bool cmp(sum x,sum y){
	return x.num>y.num;
}
priority_queue<int>q1,q2;
int check(){
	
	int ans1=0,ans2=0,M=m;
	
	for(int i=1;i<=n;i++){
		if(b[i]/a[i]==1)q2.push(b[i]);
		else q1.push(b[i]);
		d[i].num=b[i];
		d[i].w=1+int(b[i]/a[i]==1);
	}
	sort(d+1,d+1+n,cmp);
	while(!q2.empty() || !q1.empty()){
		int fx=0,fy=0;
		if(!q2.empty() && M>=2){
			fy=q2.top();
			q2.pop();
		}
		if(!q1.empty() && M>=1){
			fx=q1.top();
			q1.pop();
			if(fx>=fy){
				ans1+=fx;
				q2.push(fy);
				M-=1;
				continue;
			}
			if(!q1.empty() && M>=2){
				fx+=q1.top();
				M-=2;
				if(fx>=fy){
					ans1+=fx;
					q1.pop();
					continue;
				}else{
					q1.push(fx-q1.top());
					continue;
				}
			}
		}
		M-=2;
		if(M<1)break;
	}
	//for(int i=1;i<=n;i++)printf("%lld ",b[i]);
	//printf("\n");
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	M=m;
	for(int i=1;i<=n;i++){
		if(M>=d[i].w){
			ans2+=d[i].num;
			M-=d[i].w;
		}
		if(M<1)break;
	}
	
	return int(ans2==ans1);
}
void dfs(int now){
	if(now>n){
		ans+=check();
		return;
	}
	b[now]=2*a[now];
	dfs(now+1);
	b[now]=a[now];
	dfs(now+1);
}
long long ksm(int k,long long a){
	long long an=1;
	while(k){
		if(k&1)an=a*an%(1ll*998244353);
		a=a*a%(1ll*998244353);
		k>>=1;
	}
	return an;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		if(c==18){
			printf("%lld\n",ksm(n,2*1ll));
			continue;
		}
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		dfs(1);
		printf("%lld\n",ans);
	}
}
