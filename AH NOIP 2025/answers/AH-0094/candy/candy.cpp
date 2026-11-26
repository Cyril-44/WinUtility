#include<bits/stdc++.h>
using namespace std;

long long n,m,c[100005],y;
long long a=2e18,b=2e18;

void read(long long &res){
	res=0;long long flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	res*=flag;
	return;
}

bool check(long long x){
//	cout<<"new:"<<x<<endl;
	int j=1;
	long long wei=((long long)x/2)*a;
	if(x&1) wei+=c[j++];
//	cout<<wei<<endl;
	if(wei<=m) return true;
	while(j<=n){
//		cout<<wei<<endl;
		wei-=a;wei+=c[j]+c[j+1];
		if(wei<=m) return true;
		j+=2;
	}
	return wei<=m;
}

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i){
		read(c[i]);read(y);
		a=min(a,c[i]+y);
	}
	sort(c+1,c+n+1);
	long long l=0,r=m;
	while(l<=r){
		long long mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld",r);
	return 0;
}
