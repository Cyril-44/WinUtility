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

const i32 N=5e4+10;
i32 n,q,a[N];
i64 ans=0;
i32 main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	input(n);
	for(i32 i=1;i<=n;i++){
		input(a[i]);
	}
	input(q);
	for(i32 i=1;i<=q;i++){
		i32 l,r;
		input(l,r);
		ans=0;
		for(i32 j=1;j<=n;j++){
			i64 max=0;
			for(i32 len=l;len<=r;len++){
				i32 left_dis=std::max(len,j);
				i32 r_pos=left_dis+1;
				i64 sum=0;
				for(i32 k=r_pos-len;k<r_pos;k++){
					sum+=a[k];
				}
				while(true){
					max=std::max(max,sum);
					sum-=a[r_pos-len];
					sum+=a[r_pos];
					++r_pos;
					if(r_pos-len>j){
						break;
					}
					if(r_pos-1>n){
						break;
					}
				}
			}
			ans=ans^(j*max);
		}
		print(ans,NEW_LINE);
	}
    return 0;
}
