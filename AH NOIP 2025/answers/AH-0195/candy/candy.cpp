#include<bits/stdc++.h>
using namespace std;
struct p{
	long long v,w,sum;
}mapp[100005];
bool cmp(p a,p b){
	return a.sum<b.sum;
}
bool cmp2(p a,p b){
	return a.v<b.v;
}
long long n,m,num;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>mapp[i].v>>mapp[i].w;mapp[i].sum=mapp[i].v+mapp[i].w;}
	sort(mapp+1,mapp+n+1,cmp);
	long long sum1=mapp[1].sum;
	num+=m/mapp[1].sum*2;
	m-=mapp[1].sum*num/2;
	sort(mapp+1,mapp+n+1,cmp2);
	long long k;
	for(int i=1;i<=n;i++){
		if(m<mapp[i].v){k=i;break;}
		m-=mapp[i].v;
		num++;
	}for(int i=k;i<n;i++){
		if(m+sum1<mapp[i].v+mapp[i+1].v)break;
		if(m>=mapp[i].v+mapp[i+1].v){m-=(mapp[i].v+mapp[i+1].v);num+=2;i++;continue;}
		else if(m>=mapp[i].v){
			m-=mapp[i].v;
			num++;
		}
		else if(m<mapp[i].v+mapp[i+1].v){m+=sum1-(mapp[i].v+mapp[i+1].v);i++;}
	}cout<<num;
	return 0;
}
