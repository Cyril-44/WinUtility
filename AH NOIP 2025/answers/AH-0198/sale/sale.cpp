#include<bits/stdc++.h>
using namespace std;
int lll,t,n,m,s;
double a[5010],b[5010];
int c[5010];
struct code{
	double xing;
	int yuan,hao,jia;
}sa[5010];
int buy1(){
	int t1=m,s1;
	for(int i=1;i<=n;i++){
		if(sa[i].jia<=t1){
			t1-=sa[i].jia;
			s1++;
		}
	}
	return s1;
}
int buy2(){
	int t2=m,s2;
	for(int i=1;i<=n;i++){
		if(b[i]<=t2){
			t2-=b[i];
			s2++;
		}
	}
	return s2;
}
bool cmpp(code i,code j){
	if(i.xing<j.xing)return false;
	else if(i.xing==j.xing&&i.yuan<j.yuan)return false;
	else if(i.xing==j.xing&&i.yuan==j.yuan&&i.hao>j.hao)return false;
	return true;
}
void check(){
	for(int i=1;i<=n;i++){
		sa[i].xing=b[i];
		sa[i].yuan=a[i];
		sa[i].hao=i;
	}
	sort(sa+1,sa+1+n,cmpp);
	sort(b+1,b+1+n,greater<double>());
	if(buy1()==buy2())s=(s+1)%998244353;
}
void dfs(int x){
	if(x==n+1)check();
	b[x]=a[x];
	c[x]=1;
	dfs(x+1);
	b[x]=a[x]/2.0;
	c[x]=2;
	dfs(x+1);
}
void search(){
	dfs(1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>lll>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m;
		long long s=1;
		for(int i=1;i<=n;i++){
			s*=2;
			s%=998244353;
		}
		cout<<s<<endl;
	}
}
