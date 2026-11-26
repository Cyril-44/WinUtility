/*
cd ~/draft && g++ .cpp -std=c++14 -O2 -Wall -o 
cd ~/draft && g++ 41.cpp -std=c++14 -O2 -Wall -o 41 && ./41
*/
#include <bits/stdc++.h>
#define debug(x) cout<<"In Function "<<__FUNCTION__<<",Line "<<__LINE__<<","<<#x<<":"<<x<<"."<<endl;
#define cputime printf("CPU time used:%.3f.\n",(double)clock()/CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);++a)
#define low(a,b,c) for(a=(b);a>=(c);--a)
using namespace std;
typedef long long var;
typedef unsigned long long ull;

const int N=3e3+10,M=15;
const var mod=998244353;
const int INF=0x7fffffff;
const long long INFll=0x7fffffffffffffff;
const unsigned long long INFull=0xffffffffffffffff;

var lg2[N];
void prelg2(var x){
	var i;
	lg2[1]=0;
	upp(i,2,x){
		lg2[i]=lg2[i>>1]+1;
		//cout << i <<" "<< lg2[i] << endl;
	}
}

struct stmax{
	var st[N][M],i,j;
	void make(var *x,var y){
		upp(i,1,y){st[i][0]=x[i];}
		upp(j,1,M-1){
			upp(i,1,y){
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
	var query(var x,var y){
		//cout << x <<" "<< y <<" "<< lg2[y-x+1] <<" "<< y-(1<<lg2[y-x+1])+1 << endl;
		return max(st[x][lg2[y-x+1]],st[y-(1<<lg2[y-x+1])+1][lg2[y-x+1]]);
	}
};

var n,a[N],q,t[N<<1][2],l,r,ans[N][N],s[N<<1];
ull ans1,ans2;
stmax ss[N];
//var anss[N][N];

void code(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	var i,k,x,y;
	cin>>n;
	prelg2(n);
	upp(i,1,n){
		cin>>a[i];
	}
	upp(i,1,n){
		ans[i][1]=a[i];
		//anss[i][1]=a[i];
		s[i]=s[i-1]+a[i];
	}
	/*
	upp(i,1,n){
		upp(k,i+1,n){
			upp(j,i,k){
				anss[j][k-i+1]=s[k]-s[i-1];
			}
		}
	}
	upp(i,1,n){
		upp(k,i+1,n){
			upp(j,i,k){
				anss[j][k-i+1]=max(anss[j][k-i+1],s[k]-s[i-1]);
			}
		}
	}
	*/
	upp(k,2,n){
		l=1;r=1;
		t[l][0]=s[k];
		t[l][1]=k;
		ans[1][k]=s[k];
		upp(i,2,n){
			while(l<=r && t[l][1]<i) l++;
			while(l<=r && t[r][0]<=s[i+k-1]-s[i-1] && i+k-1<=n) r--;
			if(i+k-1<=n){
				t[++r][0]=s[i+k-1]-s[i-1];
			    t[r][1]=i+k-1;
			}
			//if(l>r) cout <<"ERR"<< endl;
			ans[i][k]=t[l][0];
		}
	}
	//var num=0;
	/*
	upp(i,1,n){
		upp(j,1,n){
			if(ans[i][j]==anss[i][j]){
				num++;
			} 
			else{
				cout << i <<" "<< j << endl;
			}
		}
	}
	cout << num <<" "<< n*n << endl;
	*/
	upp(i,1,n){
		ss[i].make(ans[i],n);
	}
	cin>>q;
	upp(i,1,q){
		cin>>x>>y;
		ans1=(ull)ss[1].query(x,y);
		upp(k,2,n){
			ans2=(ull)ss[k].query(x,y);
			ans2*=k;
			//cout << ans1 <<" "<< ans2 << endl;
			ans1=(ans1^ans2);
		}
		cout << ans1 << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	code();
	return 0;
} 