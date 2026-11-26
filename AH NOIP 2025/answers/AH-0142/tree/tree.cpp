/*
cd ~/draft && g++ .cpp -std=c++14 -O2 -Wall -o 
cd ~/draft && g++ 31.cpp -std=c++14 -O2 -Wall -o 31 && ./31
*/
#include <bits/stdc++.h>
#define debug(x) cout<<"In Function "<<__FUNCTION__<<",Line "<<__LINE__<<","<<#x<<":"<<x<<"."<<endl;
#define cputime printf("CPU time used:%.3f.\n",(double)clock()/CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);++a)
#define low(a,b,c) for(a=(b);a>=(c);--a)
using namespace std;
typedef int var;

const int N=1e6+10;
const var mod=998244353;
const int INF=0x7fffffff;
const long long INFll=0x7fffffffffffffff;
const unsigned long long INFull=0xffffffffffffffff;

var t,n,m,maxn,ans,siz[N];
var head[N],nt[N],tot,poi[N];

void add(var x,var y){
	poi[++tot]=y;nt[tot]=head[x];head[x]=tot;
}
void dfs(var u){
	var i;
	siz[u]=1;
	for(i=head[u];i;i=nt[i]){
		dfs(poi[i]);
		siz[u]+=siz[poi[i]];
	}
}
void pts8(){
	var i;
	var num=0;
	maxn=0;
	ans=0;
	dfs(1);
	for(i=head[1];i;i=nt[i]){
		maxn=max(siz[poi[i]]+1,maxn);
		if(siz[poi[i]]>1) ans+=siz[poi[i]]+1;
	    else ans+=1;
		num++;
	}
	cout << ans+maxn << endl;
}
void code(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	var i,x;
	cin>>t;
	while(t--){
		memset(head,0,sizeof(head));
		cin>>n>>m;
		upp(i,2,n){
			cin>>x;
			add(x,i);
		}
		pts8();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	code();
	return 0;
} 