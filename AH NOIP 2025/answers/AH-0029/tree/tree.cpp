#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=8010;
ll ans,T,n,m,p[maxn],b[maxn],d[maxn],sz[maxn],t[maxn];
struct node{
	ll id,d;
}a[100010];
bool cmp(node a,node b){
	return a.d>b.d;
}
vector<int> v[maxn];
void fill(int x){
	t[b[x]]=1;
	for(auto y:v[x]){
		if(y!=p[x]){
			fill(y);
		}
	}
}
ll getans(int x){
	ll sum=0;
	for(auto y:v[x]){
		if(y!=p[x]){
			sum+=getans(y);
		}
	}
	fill(x);
	for(int i=0;i<=n;i++){
		if(t[i]==0){
			sum+=i;break;
		}
	}
	for(int i=0;i<=n;i++){
		t[i]=0;
	}
	return sum;
}
void sou(int cnt){
	//cout<<cnt<<endl;
	if(cnt>n){
		ans=max(getans(1),ans);
		return;
	}
	for(int i=0;i<=n;i++){
		b[cnt]=i;
		sou(cnt+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;ans=0;
		for(int i=0;i<=n;i++){
			v[i].clear();
		}
		for(int i=2;i<=n;i++){
			cin>>p[i];
			v[p[i]].push_back(i);
		}
		for(int i=0;i<=n;i++){
			d[i]=0,sz[i]=0;t[i]=0;
		}
		sou(1);
		cout<<ans<<endl;
	}
	return 0;
}	
