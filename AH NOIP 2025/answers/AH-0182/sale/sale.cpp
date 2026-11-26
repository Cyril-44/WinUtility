#include "bits/stdc++.h"

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long int i64;
typedef float f32;
typedef double f64;

class new_line_operator{
};
std::ostream& operator << (std::ostream& lhs,const new_line_operator& rhs){
	lhs<<std::endl;
	return lhs;
}
const new_line_operator NEW_LINE;
template<typename T>
inline void print(const T& val){
	std::cout<<val;
}
template<typename T,typename ...Args>
void print(const T& val,const Args&... vals){
	std::cout<<val;
	print(vals...);
}
std::string SKIP_INPUT;
template<typename T>
inline void input(T& var){
	std::cin>>var;
}
template<typename T,typename ...Args>
void input(T& var,Args&... vars){
	std::cin>>var;
	input(vars...);
}
inline i32 moded_pow(const i32& x,const i32& y,const i32& z){
	i64 t=1;
	for(int i=0;i<y;i++){
		t*=x;
		t%=z;
	}
	t%=z;
	return t;
}

struct state{
	i32 a,p;
};
bool operator <(const state& lhs,const state& rhs){
	f32 tl=(lhs.a*1.0/lhs.p),tr=(rhs.a*1.0/rhs.p);
	if(tl!=tr){
		return tl>=tr;
	}
	else{
		return lhs.a>=rhs.a;
	}
}
const i32 N=5010,MODED_NUMBER=998244353,MAX_MONEY=10010;
i32 c,t,n,m,a[N],ans,p[N];
i64 dp[2][MAX_MONEY];
state logic[N];
inline i64 get_dp(const i32& layer,const i32& money){
	if(layer==-1){
		return 0;
	}
	return dp[layer%2][money];
}
inline void set_dp(const i32& layer,const i32& money,const i64& val){
	if(layer==-1){
		return;
	}
	dp[layer%2][money]=val;
};
inline void clear_dp(){
	memset(dp,0,sizeof(dp));
}
void dfs(i32 layer){
	if(layer==n+1){
		clear_dp();
		for(i32 i=1;i<=n;i++){
			for(i32 j=0;j<=m;j++){
				if(j>=p[i]){
					set_dp(i,j,std::max(get_dp(i-1,j),get_dp(i-1,j-p[i])+a[i]));
				}
				else{
					set_dp(i,j,get_dp(i-1,j));
				}
			}
		}
		i32 standard=get_dp(n,m);
		for(i32 i=1;i<=n;i++){
			logic[i].a=a[i];
			logic[i].p=p[i];
		}
		i32 logic_ans=0,cost=0;
		std::sort(logic+1,logic+n+1);
		for(i32 i=1;i<=n;i++){
			if(cost+logic[i].p<=m){
				logic_ans=(logic_ans+logic[i].a);
				cost+=logic[i].p;
			}
			else{
				if(cost==m){
					break;
				}
				continue;
			}
		}
		if(standard==logic_ans){
			++ans;
			ans%=MODED_NUMBER;
		}
		return;
	}
	for(i32 i=1;i<3;i++){
		p[layer]=i;
		dfs(layer+1);
	}
}	
i32 main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	input(c,t);
	for(i32 i=1;i<=t;i++){
		input(n,m);
		for(i32 j=1;j<=n;j++){
			input(a[j]);
		}
		if(n<=10){
			ans=0;
			dfs(1);
			print(ans%MODED_NUMBER,NEW_LINE);
		}
		else{
			print(moded_pow(2,n,MODED_NUMBER),NEW_LINE);
		}
	}
    return 0;
}
