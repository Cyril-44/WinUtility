#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct L{
	long long x,y;
};
bool cmp(L a,L b){
	return a.x<b.x;
}
long long n,m;
L a[MAXN];
long long b[MAXN],cnt;
long long mi,o;
long long sum;
bool vis[MAXN];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	mi=10000000000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x+a[i].y<mi){
			mi=a[i].x+a[i].y;
			o=i;
		}
	}
	sum+=(m/mi)*2;
	m%=mi;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].x*2<=mi){
			b[++cnt]=a[i].x;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(b[i]<=m){
			sum++;m-=b[i];
		}
		else if(cnt-i+1>=2){
			sum--;m=m+mi-b[i];
		}
	}
	cout<<sum;
	return 0;
}
