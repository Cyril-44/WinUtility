#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
}a[100005];
long long two[100005];
long long one[100005];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		two[i]=a[i].x+a[i].y;
		one[i]=a[i].x;
		sum+=a[i].x;
	}
	sort(two+1,two+n+1);
	sort(one+1,one+n+1);
	m-=sum;
	long long ans=m/two[1]*2;
	//cout<<ans<<" "<<sum<<endl;
	sum+=m-ans/2*two[1];
	one[n+1]=INT_MAX*2ll;
	for(int i=1;i<=n;i++){
		if(one[i]+one[i+1]<two[1]){
			if(sum<one[i]+one[i+1]){
				if(sum<one[i])break;
				sum-=one[i];
				ans++;
				break;
			}
			sum-=one[i];;
			ans++;
		}
		else{
			ans+=max((sum-one[i])/two[1]*2ll+1,sum/two[1]*2ll);
			break;
		}
	}
	cout<<ans;
	return 0;
}
