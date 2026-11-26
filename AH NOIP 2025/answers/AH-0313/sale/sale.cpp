#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long c,t;
long long C[5005][5005];
long long a[5005];
long long n,m;
long long ans;
struct good{
	long long w,v;
	bool operator<(const good &b)const{
		if(w*b.v!=v*b.w) return w*b.v>v*b.w;
		return w>b.w;
	}
};
good s[5005];
good tmp[15];
long long vis[15];
long long dfs2(long long k=1,long long cur=m,long long nw=0){
	if(k>n||cur==0) return nw;
	if(cur<s[k].v) return dfs2(k+1,cur,nw);
	else return max(dfs2(k+1,cur,nw),dfs2(k+1,cur-s[k].v,nw+s[k].w));
}
void dfs1(long long k){
	if(k==n+1){
		for(long long i=1;i<=n;i++) tmp[i]=s[i];
		sort(tmp+1,tmp+n+1);
		long long ans1=0,nc=m;
		long long a1=-1,a2=-1,a3=-1;
		memset(vis,0,sizeof(vis));
		int flag=0;
		for(long long i=1;i<=n;i++){
			if(tmp[i].v<=nc){
				nc-=tmp[i].v;
				ans1+=tmp[i].w;
			}else if(nc==1) flag=1;
		}
		if(!flag||ans1==dfs2(1)) ans++;
		// for(long long i=1;i<=n;i++) cout<<tmp[i].w<<'/'<<tmp[i].v<<'\n'; cout<<'\n';
		// cout<<"ans1="<<ans1<<' '<<"ans2="<<ans2<<";\n";
		return;
	}
	s[k].v=1;dfs1(k+1);
	s[k].v=2;dfs1(k+1);
}
void solve1(){
	ans=0;
	dfs1(1);
	cout<<ans<<'\n';
}
int a[5005];
// void solve2(){
// 	for(int i=1;i<=n;i++) a[i]=s[i].w;
// 	sort(a+1,a+1+n);
// 	for(int i=1;i<=n;i++){
// 		if((m-i)%2==0) continue;
// 		for(int j=1;j<=n-i+1;j++){
// 			if(i>j) continue;
			
// 		}
// 	}
// }
long long pw2[10005];
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	C[0][0]=1;
	for(long long i=0;i<=5000;i++){
		for(long long j=0;j<=5000;j++){
			C[i][j]%=p; C[i+1][j]+=C[i][j];
		}
	}
	pw2[0]=1;
	for(int i=1;i<=10000;i++){
		pw2[i]=pw2[i-1]<<1; pw2[i]%=p;
	}
	cin>>c>>t; while(t--){
		cin>>n>>m;
		for(long long i=1;i<=n;i++) cin>>s[i].w;
		if(c<=5) solve1();
		if(c==18){
			cout<<pw2[n]<<'\n'; 
		}
		// if(c==10||c==11||c==12||c==19||c==20){
		// 	solve2();
		// }
	}
	return 0;
}