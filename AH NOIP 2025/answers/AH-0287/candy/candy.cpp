#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
long long n,m,rest,num=0,ans=0;
struct node {
	long long x,y;
}a[1000005];
bool cmp (node a,node b){
	return a.x<b.x;
}
bool cmpp (node a,node b){
	return a.x+a.y<b.x+b.y;
}
void worka(){
	sort(a+1,a+1+n,cmp);
	cout <<m/a[1].x<<endl;
	return ;
}
void workb(){ 
	sort(a+1,a+1+n,cmpp);
	long long num=m/(a[1].x+a[1].y);
	long long rest=m-num*(a[1].x+a[1].y);
	num*=2;
	sort(a+1,a+1+n,cmp);
	for (long long i=1;i<=n;i++){
		if (rest>=a[i].x) num++,rest-=a[i].x;
		else break;
	}
	cout <<num<<endl;
	return ;
}
priority_queue <long long> q;
int main (){
	freopen ("candy.in","r",stdin);
	freopen ("candy.out","w",stdout);
	long long ok1=1,ok2=1;
	cin >>n>>m;
	for (long long i=1;i<=n;i++){
		cin >>a[i].x>>a[i].y;
		if (a[i].x!=a[i].y) ok1=0;
		if (a[i].x<=a[i].y) ok2=0;
	}
	if (n==1) {
		long long tot=a[1].x+a[1].y;
		num=m/tot;
		long long rest=m-num*tot;
		cout <<num*2+rest/a[1].x<<endl;
		return 0;
	}
	if (n==2) {
		for (long long a1=0;a1<=m;a1++){
			for (long long b1=0;b1<=m;b1++){
				if (a1*a[1].x+a1*a[1].y+b1*a[2].x+b1*a[2].y<=m) ans=max(ans,a1*2+b1*2);
				if (a1*a[1].x+(a1-1)*a[1].y+b1*a[2].x+b1*a[2].y<=m) ans=max(ans,a1*2+b1*2-1);
				if (a1*a[1].x+a1*a[1].y+b1*a[2].x+(b1-1)*a[2].y<=m) ans=max(ans,a1*2+b1*2-1);
				if (a1*a[1].x+(a1-1)*a[1].y+b1*a[2].x+(b1-1)*a[2].y<=m) ans=max(ans,a1*2+b1*2-2);
			}
		}
		cout <<ans<<endl;
		return 0;
	}
	if (ok1==1){
		worka();
		return 0;
	}
	if (ok2==1){
		workb();
		return 0;
	}
	sort(a+1,a+1+n,cmpp);
	long long num=m/(a[1].x+a[1].y);
	long long rest=m-num*(a[1].x+a[1].y);
	q.push(a[1].x);
	q.push(a[1].y);
	a[1].x=1e9;
	a[1].y=1e9;
	num*=2;
	sort(a+1,a+1+n,cmp);
	for (long long i=1;i<=n;i++){
		if (a[i].x<=rest) num++,rest-=a[i].x;
		else if (q.top()>a[i].x) rest+=q.top(),rest-=a[i].x,q.pop(),q.push(a[i].x);
	}
	cout <<num<<endl;
	return 0;
}
/*
3 15
1 7
2 3
3 1
*/
