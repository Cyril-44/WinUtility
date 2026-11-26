#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5+10;
int m,n,sum;
int a[N],b[N],ans=21483688;
int minn(int a,int b){
	if(a>=b)return b;
	else return a;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans=minn(ans,a[i]+b[i]);
	}
	sort(a+1,a+n+1);
	sum=m/ans;
	sum=sum*2;
	int y=m%ans,i=1;
	while(y>=0&&y-a[i]>=0){
		y=y-a[i];
		sum++;
		i++;
	}
	cout<<sum<<endl;
	return 0;
}
