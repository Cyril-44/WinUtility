#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long m,minN,minN2;
int n,vis[N];
struct node{
	long long a,b;
}num[N];
bool cmp(node x,node y){
	return x.a<y.a;
}
int les[N],check[N],h=0;
long long deal(long long x,int now){
	long long cnt=x/minN;
	cnt*=2;
	x%=minN;
	long long minN3;
	minN3=min(minN2,num[now+1].a);
	if(x>minN3){
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&num[i].a,&num[i].b);
	}
	sort(num+1,num+n+1,cmp);
	minN=1e18;
	for(int i=1;i<=n;i++){
		if(num[i].a+num[i].b<minN){
			minN=num[i].a+num[i].b;
			h=0;
			les[++h]=i;
		}
		else{
			if(num[i].a+num[i].b==minN){
				les[++h]=i;
			}
		}
	}
	for(int i=1;i<=h;i++){
		check[les[i]]=1;
	}
	long long tot=0;
	minN2=1e18;
	int las=0;
	for(int i=1;i<=n;i++){
		if(m>=num[i].a){
			if(deal(m,las)>(deal(m-num[i].a,i)+1)){
				break;
			}
			tot++,m-=num[i].a;
			minN2=min(minN2,num[i].b);
			las=i;
		}
	}
	tot+=(m/minN)*2;
	m=m%minN;
	if(m>minN2){
		tot++;
	}
	printf("%lld",tot);
	
	
	return 0;
}
/*
3 15
1 7
2 3
3 1
*/
