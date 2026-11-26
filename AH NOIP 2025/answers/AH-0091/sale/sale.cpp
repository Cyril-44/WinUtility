#include<bits/stdc++.h>
using namespace std;
long long ksm(long long x,long long y,long long p){
	long long res=1;
	while(y!=0){
		if(y%2==1)  res=res*x%p;
		x=x*x%p,y/=2;
	}return res;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long tc,ggg,tx,ty,t1;
	scanf("%lld%lld",&tc,&ggg);
	for(int gg=0;gg<ggg;gg++){
		scanf("%lld%lld",&tx,&ty);
		for(int i=0;i<tx;i++)  scanf("%lld",&t1);
		cout<<ksm(2,tx,998244353)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
