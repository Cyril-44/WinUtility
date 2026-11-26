#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct Node{
	long long x,y;
}p[N];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	long long Mn=1e18;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		Mn=min(Mn,p[i].x+p[i].y);
	}
	sort(p+1,p+n+1,cmp);
	long long ans=0,sum=0;
	//cout<<Mn<<endl;
	ans=2*(m/Mn);
	for(int i=1;i<=n;i++){
		sum+=p[i].x;
		//cout<<p[i].x<<endl;
		//cout<<sum<<' '<<(m-sum)/Mn<<endl;
		ans=max(ans,i+2*((m-sum)/Mn));
	}
	cout<<ans<<'\n';
	return 0;
}
