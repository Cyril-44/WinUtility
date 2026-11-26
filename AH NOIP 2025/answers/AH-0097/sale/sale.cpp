#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=5009;
int Casenum,T;
struct candy256{
	int x,y,id;
	inline bool operator < (const candy256& temp)const{
		if(x*temp.y>y*temp.x){
			return 1;
		}
		else if(x*temp.y==y*temp.x){
			if(x>temp.x){
				return 1;
			}
			else{
				return id<temp.id;
			}
		}
		else{
			return 0;
		}
	}
}a[N],b[N];
int n,m,f[N*2],res=0;
void DP(){
	// cout<<"SDFSDFSDFSDF"<<endl;
	res=0;
	for(int i=0;i<=m+9;i++){
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i].y;j--){
			f[j]=max(f[j],f[j-a[i].y]+a[i].x);
		}
		// for(int j=0;j<=m;j++){
		// 	cout<<f[j]<<" ";
		// }
		// cout<<endl;
	}
	// for(int i=0;i<=m;i++){
	// 	cout<<f[i]<<" ";
	// }
	// cout<<endl;
	for(int i=0;i<=m+1;i++){
		res=max(res,f[i]);
	}
	return;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>Casenum>>T;
	while(T--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;
			a[i].id=i;
		}
		for(int S=0;S<(1<<n);S++){
			int temp=m;
			for(int i=1;i<=n;i++){
				if((S>>(i-1))&1){
					a[i].y=2;
				}
				else{
					a[i].y=1;
				}
			}
			DP();
			for(int i=1;i<=n;i++){
				b[i]=a[i];
			}
			sort(b+1,b+n+1);
			// for(int i=1;i<=n;i++){
			// 	cout<<b[i].y<<" ";
			// }
			// cout<<endl;
			// for(int i=1;i<=n;i++){
			// 	cout<<b[i].x<<" ";
			// }
			// cout<<endl;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(temp>=b[i].y){
					temp-=b[i].y,cnt+=b[i].x;
				}
			}
			// cout<<res<<" "<<cnt<<endl<<"_____________"<<endl;
			ans+=(cnt==res);
			// if(cnt!=res){
			// 	for(int i=1;i<=n;i++){
			// 		cout<<b[i].y<<" ";
			// 	}
			// 	cout<<endl;
			// 	for(int i=1;i<=n;i++){
			// 		cout<<b[i].x<<" ";
			// 	}
			// 	cout<<endl;
			// }
		}
		cout<<ans<<endl;
	}
	return 0;
}