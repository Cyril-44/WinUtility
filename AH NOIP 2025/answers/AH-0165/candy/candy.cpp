#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
}a[1000100];
long long n,m;
long long c[1001000];
int sf[1001000];
long long d[1001000];
/*
long long max_num(long long i,long double x){
	long long l=0,r=1000000;
	while(l<r){
		long long mid=(l+r)/2+1;
		long double sum=mid*b[i]+(mid+1)*a[i];
		if(sum/(2*mid+1)<=x){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
long long price(long long i,long long x){
	return x*b[i]+(x+1)*a[i];
}
*/
/*
bool check(long double x){
	long long mm=0;
	for(int i=1;i<=n;i++){
		if((a[i]+b[i])*1.0/2<=x){
			return 1;
		}else{
			if(a[i]>=b[i]){
				continue;
			}else{
				
			}
		}
	}
	return 0;
}
*/
bool cmp(node a,node b){
	return a.a<b.a;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	long long minn=1000000000000000ll;
	long long minx;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		c[i]=a[i].a+a[i].b;
		if(c[i]<minn){
			minn=c[i];
			minx=i;
		}
	}
	long long mm=0,mn=0,jl=0;
	bool endd=0;
	for(int i=1;i<=n;i++){
		if(a[i].a*2>=minn){
			break;
		}
		if(mm+a[i].a<=m){
			//cout<<a[i].a<<" ";
			mm+=a[i].a;
			jl=a[i].a;
			mn++;
			sf[i]=1;
		}else{
			endd=1;
			break;
		}
	}
	//cout<<endl;
	if(endd){
		cout<<mn<<endl;
		return 0;
	}
	//if(sf[minx]==1){
		//cout<<"yes"<<" ";
	//}
	//cout<<mm<<" "<<mn<<endl;
	/*
	if(sf[minx]==1){
		if(mm+a[minx].b<=m){
			mm+=a[minx].b;
			mn++;
			sf[minx]=0;
		}else{
			cout<<mn<<endl;
			return 0;
		}
	}
	cout<<mm<<" ";
	*/
	/*
	long long l=0,r=1000000000000000000ll/(a[minx].a+a[minx].b);
	while(l<r){
		long long mid=(l+r)/2+1;
		long long sum=mid*(a[minx].b+a[minx].a);
		if(mm+sum<=m){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	mm+=l*(a[minx].b+a[minx].a);
	mn+=l*2;
	*/
	//cout<<a[minx].a<<" ";
	long long cnt=(m-mm)/minn;
	mn+=cnt*2;
	mm+=cnt*(a[minx].a+a[minx].b);
	//cout<<mm<<" "<<mn<<" ";
	for(int i=1;i<=n;i++){
		if(sf[i]==1){
			d[i]=a[i].b;
			/*
			if(mm+a[i].b<=m){
				mm+=a[i].b;
				mn++;
				sf[i]=0;
				break;
			}
			*/
		}else{
			d[i]=a[i].a;
		}
	}
	sort(d+1,d+n+1);
	long long tmp=1000000000000000000ll;
	for(int i=1;i<=n;i++){
		tmp=min(tmp,d[i]);
		if(mm+d[i]<=m){
			mm+=d[i];
			mn++;
		}
	}
	//cout<<jl<<" "<<a[minx].a+a[minx].b<<" ";
	if(mm-jl+a[minx].a+a[minx].b<=m){
		//cout<<"yes";
		mn++;
	}
	cout<<mn<<endl;
	/*
	long double l=0,r=1000000000000000000ll;
	while(r-l>=0.000001){
		long double mid=(l+r)/2+1;
		if(check(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	long long mm=0;
	for(int i=1;i<=n;i++){
		if(b[i]<=x){
			return 1;
		}else{
			if(a[i]>=b[i]){
				continue;
			}else{
				long long l=0,r=1000000;
				while(l<r){
					long long mid=(l+r)/2+1;
					long double sum=mid*b[i]+(mid+1)*a[i];
					if(sum/(2*mid+1)<=x){
						l=mid;
					}else{
						r=mid-1;
					}
				}
				long long sum=l*b[i]+(l+1)*a[i];
				mm+=sum;
				if(mm>=m){
					return 1;
				}
			}
		}
	}
	*/
	return 0;
}
