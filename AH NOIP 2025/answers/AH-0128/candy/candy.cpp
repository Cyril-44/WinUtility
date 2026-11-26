#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 500 ;
int n , m , ans ;
struct node{
	int x , y ;
}a[N] ;
bool cmp(node g , node h){
	if(g.x > h.x){
		return 0 ;
	}else if(g.x < h.x){
		return 1 ;
	}else{
		return g.y < h.y ;
	}
}
int main(){
	freopen("candy.in" , "r" , stdin) ;
	freopen("candy.out" , "w" , stdout) ;
	bool YN = 1 ;
	int minn = -1 ;
	scanf("%d%d" , &n , &m) ;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d%d" , &a[i].x , &a[i].y) ;
		if(a[i].x != a[i].y) YN = 0 ;
		minn = min(minn , a[i].x) ;
	}
	if(YN){
		cout << m / minn << endl ;
	}else{
		while(m > 0){
			sort(a+1,a+n+1,cmp) ;
			if(m >= a[1].x){
				m -= a[1].x ;
				ans++ ;
				swap(a[1].x , a[1].y) ;
			}else{
				break ;
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}
