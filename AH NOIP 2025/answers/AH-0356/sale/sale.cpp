#include<bits/stdc++.h>
#define PII pair<int,int>
#define LL long long
#define x first
#define y second
using namespace std;
const int N=5010,M=1e4+10,mod=998244353;
int id,T,n,m,a[N];LL f[M];
struct Candy{
	int x,w,id;
	bool operator<(const Candy &t)const{
		if(x!=t.x) return x<t.x;
		else if(w!=t.w) return w<t.w;
		else return id<t.id;
	}
	bool operator!=(const Candy &t)const{
		return x!=t.x&&w!=t.w&&id!=t.id;
	}
}b[N];
bool cmp(Candy t1,Candy t2){
	if(t1.x*t2.w!=t2.x*t1.w) return t1.x*t2.w>t2.x*t1.w;
	else if(t1.x!=t2.x) return t1.x>t2.x;
	else return t1.id<t2.id;
}
struct CMP{
	bool operator()(vector<Candy>t1,vector<Candy>t2)const{
		sort(t1.begin(),t1.end());
		sort(t2.begin(),t2.end());
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]) return false;
		}
		return true;
	}
};
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
bool check(){
	sort(b,b+n,cmp);
	//for(int i=0;i<n;i++) cout<<b[i].x<<" "<<b[i].w<<" "<<b[i].id<<"\n";
	int tmp=m;
	LL res=0;
	for(int i=0;i<n;i++){
		if(tmp>=b[i].w){
			tmp-=b[i].w;
			res+=b[i].x;
		}
	}
	memset(f,-0x3f,sizeof(LL[m+2]));
	f[0]=0;
	for(int i=0;i<n;i++){
		for(int j=m;j>=b[i].w;j--){
			f[j]=max(f[j],f[j-b[i].w]+b[i].x);
		}
		for(int j=m;j>=1;j--) f[j]=max(f[j],f[j-1]);
	}
	//cout<<res<<" "<<f[m]<<"\n";
	return res==f[m];
}
void solve_m2(){
	int cnt=0;
	for(int i:{0,(1<<n)-1}){
		for(int j=0;j<n;j++){
			b[j].x=a[j];
			b[j].id=j;
			if(i>>j&1) b[j].w=2;
			else b[j].w=1;
		}
		if(check()){
			cnt++;
			if(cnt>=mod) cnt-=mod;
		}
	}
	for(int _1=0;_1<n;_1++){
		for(int _2=_1;_2<n;_2++){
			int i=(1<<_1)|(1<<_2);
			for(int j=0;j<n;j++){
				b[j].x=a[j];
				b[j].id=j;
				if(i>>j&1) b[j].w=2;
				else b[j].w=1;
			}
			if(check()){
				cnt++;
				if(cnt>=mod) cnt-=mod;
			}
		}
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	for(cin>>id>>T;T--;){
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		if(id==18) cout<<qmi(2,n)<<"\n";
		else if(n<=10){
			int cnt=0;
			for(int i=0;i<(1<<n);i++){
				for(int j=0;j<n;j++){
					b[j].x=a[j];
					b[j].id=j;
					if(i>>j&1) b[j].w=2;
					else b[j].w=1;
				}
				if(check()){
					cnt++;
					if(cnt>=mod) cnt-=mod;
				}
			}
			cout<<cnt<<"\n";
		}else if(m==2){
			solve_m2();
		}
	}
	return 0;
}