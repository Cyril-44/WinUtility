#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m;
struct candy_t{
	long long x,y,z;
}candy[200000];
bool cmp(candy_t a,candy_t b){
    if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
long long ans=0;
vector<long long> temp;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>candy[i].x>>candy[i].y;candy[i].z=candy[i].x+candy[i].y;
	}
	long long minz=candy[1].z;
	for(long long i=2;i<=n;i++){
		if(candy[i].z<minz)minz=candy[i].z;
	}
	sort(candy+1,candy+n+1,cmp);
	long long pos;
	for(pos=1;pos<=n;pos++){
		if(2*candy[pos].x>minz||m-candy[pos].x<0){
            pos--;break;
		}
		ans++;
		m=m-candy[pos].x;
	}
	ans+=(m/minz)*2;
	m=m%minz;
	if(candy[pos+1].x<=m)ans++;
	cout<<ans;
	return 0;
}
