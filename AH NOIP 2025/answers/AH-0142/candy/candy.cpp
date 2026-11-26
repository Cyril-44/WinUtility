/*
cd ~/draft && g++ 12.cpp -std=c++14 -O2 -Wall -o 12
cd ~/draft && g++ 12.cpp -std=c++14 -O2 -Wall -o 12 && ./12
*/
#include <bits/stdc++.h>
#define debug(x) cout<<"In Function "<<__FUNCTION__<<",Line "<<__LINE__<<","<<#x<<":"<<x<<"."<<endl;
#define cputime printf("CPU time used:%.3f.\n",(double)clock()/CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);++a)
#define low(a,b,c) for(a=(b);a>=(c);--a)
using namespace std;
typedef long long var;

const int N=1e6+10;
const var mod=998244353;
const int INF=0x7fffffff;
const long long INFll=0x7fffffffffffffff;
const unsigned long long INFull=0xffffffffffffffff;

struct node{
	var v1,v2;
	bool operator < (const node x) const {
		return v1<x.v1;
	}
};

var n,m,min1,min2,lim,tot,stop;
node xy[N];

void code(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	var i;
	cin>>n>>m;
	min1=min2=INFll;
	upp(i,1,n){
		cin>>xy[i].v1>>xy[i].v2;
		if(min1>xy[i].v1+xy[i].v2 || (min1>=xy[i].v1+xy[i].v2 && min2>xy[i].v1)){
			min1=xy[i].v1+xy[i].v2;
			min2=xy[i].v1;
		}
	}
	sort(xy+1,xy+1+n);
	//upp(i,1,n){cout << xy[i].v1 <<" "<< xy[i].v2 << endl;}
	lim=min1>>1;
	upp(i,1,n){
		if(xy[i].v1<=lim){
			m-=xy[i].v1;
			++tot;
			//cout << m <<" "<< tot << endl;
		}
		else{
			stop=i;
			break;
		}
	}
	if(!stop){stop=n+1;}
	tot+=(m/(min1))*2;
	m/=min1;
	if(xy[stop].v1<=min1-min2 && stop<=n){
		for(;stop<=n;++stop){
			if(m>=xy[stop].v1){
				m-=xy[stop].v1;
				++tot;
			}
			else{
				break;
			}
		}
	}
	else{
		++tot;
	}
	cout << tot << endl;
	//cputime;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	code();
	return 0;
} 