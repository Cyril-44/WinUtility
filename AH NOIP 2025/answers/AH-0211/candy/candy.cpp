#include<iostream>
#include<algorithm>
using namespace std;
int n,m,min1,min2,max8=0,oo2,mmin,x1,x2;
double oo1;
bool f1=1;
struct node{
	int first,second;
}candy[100001];
bool cmm1(node xo1,node xo2){
	if(xo1.first<xo2.first){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>candy[i].first>>candy[i].second;
		if(i==1){
			min1=candy[i].first,min2=candy[i].second;
			oo2=candy[i].first+candy[i].second;
			x1=i;
		}
		if((candy[i].first+candy[i].second)<oo2){
			oo2=candy[i].first+candy[i].second;
			x1=i;
		}
		min1=min1<candy[i].first?min1:candy[i].first;
		if(candy[i].first!=candy[i].second){
			f1=0;
		}
	}
	if(f1==1){
		max8=m/min1;
	}
	else{
		sort(candy+1,candy+1+n,cmm1);
		oo1=((double)(oo2))/2.0;
		for(int i=1;i<=n;++i){
			if(candy[i].first<oo1){
				++max8;
				m-=candy[i].first;
				swap(candy[i].first,candy[i].second);
			}
			else{
				mmin=candy[i].first;
				x2=i;
				break;
			}
		}
		if(m>=oo2){
			max8+=m/oo2*2;
			m-=(m/oo2)*oo2;
		}
		sort(candy+1,candy+1+n,cmm1);
		for(int i=1;i<=10;++i){
			if(m>=candy[i].first){
				m-=candy[i].first;
				++max8;
				if(candy[i].second<candy[i+1].first&&candy[i].second<=m){
					m-=candy[i].second;
					++max8;
					break;
				}
			}
			else break;
		}
	}
	cout<<max8;
	return 0;
}
