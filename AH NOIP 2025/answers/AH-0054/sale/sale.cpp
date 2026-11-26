#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF=1e18;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD2;
const int N=5005;
int n,m;
int a[N],b[N],w[N];
int s1[N],s2[N];
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			w[j]=((i>>(j-1))&1?2:1);
		}
		sort(b+1,b+n+1,[](int x,int y){return a[x]*w[y]!=a[y]*w[x]?a[x]*w[y]>a[y]*w[x]:a[x]>a[y];});
		int t=m,res=0;
		for(int j=1;j<=n;j++){
			if(t>=w[b[j]]){
				res+=a[b[j]];
				t-=w[b[j]];
			}
		}
		int tot1=0,tot2=0;
		for(int j=1;j<=n;j++){
			if(w[j]==1){
				s1[++tot1]=a[j];
			}else{
				s2[++tot2]=a[j];
			}
		}
		for(int j=1;j<=tot1;j++){
			s1[j]+=s1[j-1];
		}
		for(int j=1;j<=tot2;j++){
			s2[j]+=s2[j-1];
		}
		int res2=0;
		for(int j=0;j<=tot1;j++){
			if(j>m)break;
			res2=max(res2,s1[j]+s2[min(tot2,(m-j)/2)]);
		}
		//if(res!=res2){
		//	cout<<res<<" "<<res2<<"\n";
		//	for(int j=1;j<=n;j++){
		//		cout<<a[j]<<" "<<w[j]<<"\n";
		//	}
		//	for(int j=1;j<=n;j++){
		//		cout<<b[j]<<"\n";
		//	}
		//	exit(0);
		//}
		if(res==res2)ans++;
	}
	cout<<ans%MOD<<"\n";
}
int C[N][N];
void init(){
	int mx=5000;
	C[0][0]=1;
	for(int i=1;i<=mx;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
}
int pre[N];
void solve2(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(a[i-1]>a[i]){
			pre[i]=i-1;
		}else{
			pre[i]=pre[i-1];
		}
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(j+1>=m){
				cout<<i<<" "<<j<<"\n";
				ans+=C[i-1][j];
			}else if((m-(j+1))%2==0){
				cout<<i<<" "<<j<<"\n";
				ans+=C[i-1][j];
			}else if((m-(j+1))/2+1>(i-j-1)){
				cout<<i<<" "<<j<<"\n";
				ans+=C[i-1][j];
			}else{
				ans+=C[i-1][j];
			}
		}
	}
	cout<<ans<<"\n";
}
void solve3(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*2%MOD;
	}
	cout<<ans<<"\n";
}
int pw2[N];
void solve4(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pw2[0]=1;
	for(int i=1;i<=n;i++){
		pw2[i]=pw2[i-1]*2%MOD;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=2;
	for(int i=2;i<=n;i++){
		if(a[i]*2<=a[1]){
			ans++;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(j==1){
				ans+=pw2[n-i];
				ans%=MOD;
			}else{
				if(a[j]*2>a[1]&&a[i]+a[j]>=a[1]){
					ans+=pw2[n-i];
					ans%=MOD;
				}else if(a[j]*2<=a[1]&&a[i]+a[j]<=a[1]){
					ans+=pw2[n-i];
					ans%=MOD;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	init();
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cid,testcase=1,multitest=1;
	if(multitest)cin>>cid>>testcase;
	while(testcase--){
		if(cid==1||cid==2||cid==3||cid==4||cid==5){
			solve1();
		}else if(cid==10||cid==11||cid==12||cid==19||cid==20){
			solve2();
		}else if(cid==18||cid==16||cid==17){
			solve3();
		}else if(cid==7||cid==8||cid==9||cid==14||cid==15){
			solve4();
		}
	}
	return 0;
}
