#include <iostream>
using namespace std;
const int N=5e4+5;
const long long oo=1e15;
int n,q,a[N],lg2[N];
long long sum[N],mi[19][N],ans[N],mi2[19][N];
long long qmin(int x,int y){
	if(x>y) return oo;
	int len=lg2[y-x+1];
	return min(mi[len][x],mi[len][y-(1<<len)+1]);
}
long long qmi2(int x,int y){
	if(x>y) return oo;
	int len=lg2[y-x+1];
	return max(mi2[len][x],mi2[len][y-(1<<len)+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	lg2[1]=0;
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+1ull*a[i],mi[0][i]=sum[i];
	for(int j=1;j<19;j++){
		for(int i=0;i<=n;i++){
			if((i+(1<<j)-1)>n) break;
			mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
		}
	}
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		unsigned long long res=0;
		if(l==r){
			for(int i=l;i<=n;i++){
				mi2[0][i]=sum[i]-sum[i-l];
			}
			for(int j=1;j<19;j++){
				for(int i=l;i<=n;i++){
					if(i+(1<<j)-1>n) break;
					mi2[j][i]=max(mi2[j-1][i],mi2[j-1][i+(1<<(j-1))]);
				}
			}
			for(int i=1;i<=n;i++){
				ans[i]=qmi2(max(l,i),min(i+r-1,n));
				res^=(1ull*i*ans[i]);
			}
			cout<<res<<"\n";
			continue;
		}
		
		for(int i=1;i<=n;i++){
			ans[i]=-oo;
			for(int j=max(i,l);j<=i+r-1&&j<=n;j++){
				ans[i]=max(ans[i],sum[j]-qmin(max(j-r,0),min(i,j-l+1)-1));
			}
			res^=(1ull*i*ans[i]);
		}
		cout<<res<<'\n';
	}
	
	return 0;
}
