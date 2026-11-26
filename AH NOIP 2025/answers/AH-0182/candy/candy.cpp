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

const i32 N=1e5+10,MAX=1e4+10;
i32 m;
i32 n,a[N][2],dp[2][MAX];
inline i32 get_dp(const i32& layer,const i32& money){
	if(layer==-1){
		return 0;
	}
	return dp[layer%2][money];
}
inline void set_dp(const i32& layer,const i32& money,const i32& val){
	if(layer==-1){
		return;
	}
	dp[layer%2][money]=val;
}
i32 main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	memset(dp,0,sizeof(dp));
	input(n,m);
	for(i32 i=1;i<=n;i++){
		input(a[i][0],a[i][1]);//9223372036854775807
		a[i][1]=a[i][0]+a[i][1];
	}
	for(i32 i=1;i<=n;i++){
		for(i32 j=1;j<=m;j++){
			for(i32 k=0;k<=j;k++){
				i32 pair=k/2;
				i32 add_first=k%2;
				i32 cost=pair*a[i][1]+add_first*a[i][0];
				if(cost>j){
					break;
				}
				else{
					i32 rest=j-cost;
					set_dp(i,j,std::max(get_dp(i,j),get_dp(i-1,rest)+k));
				}
			}
		}
	}
	i32 ans=0;
	ans=get_dp(n,m);
	print(ans);
    return 0;
}
