#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+10;
int n,m,ans,k;
struct ss{
	int ji,ou,he;
}a[maxn];
bool cmp(const ss &x,const ss &y){
	if(x.he!=y.he){
		return x.he<y.he;
	}
	else{
		return x.ji<y.ji;
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].ji>>a[i].ou;
		a[i].he=a[i].ji+a[i].ou;
		if(a[i].ji==a[i].ou){
			k++;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(k==n){
		cout<<n/a[1].ji;
		return 0;
	}
	if(m%a[1].he==0){
		int aa=m/a[1].he;
		ans+=aa*2;
	}
	else{
		int aa=m%a[1].he;
		ans+=aa*2;
	}
	m%=a[1].he;
	int i=1;
	while(m>0){
		if(i==n){
			break;
		}
		if(m>=min(a[i].ji,a[i+1].ji)){
			m-=min(a[i].ji,a[i+1].ji);
			ans++;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
