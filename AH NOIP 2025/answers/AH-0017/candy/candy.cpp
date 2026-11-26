#include<bits/stdc++.h>
#define ll long long
#define itn int
#define gc getchar
#define pc putchar
#define scf scanf
#define prf printf
#define fu(v,s,e) for(int v=(s);v<=(e);v++)
#define fd(v,s,e) for(int v=(s);v>=(e);v--)
using namespace std;
int _t;
ll in(){
    ll x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') c=gc(),f=-1;
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return x*f;
}
template<typename _Tp>
void out(_Tp x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
template<typename _Tp>
void out(_Tp x,char c){out(x),pc(c);}
int n,x[100005],y[100005],mns=2085111415/*TECHNOPOLIS 2085 HD11,IN14,AT15*/,b[100005];
ll m,ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    // _t=in();
    // while(_t--){
    // }
    n=in(),m=in();
    fu(i,1,n) b[i]=x[i]=in(),y[i]=in(),mns=min(mns,x[i]+y[i]);
    sort(b+1,b+1+n);
    ans=m/mns*2,m%=mns;
    b[n+1]=mns-b[n];
    fu(i,1,n) if(m>=b[i]) m-=b[i],ans++;
    else if(b[i]+b[i+1]<mns) m+=mns-b[i]-b[i+1],i++;
    out(ans,'\n');
    // cerr<<clock()/1000.0<<'\n';
    return 0;
}
/*
> 在太阳西斜的这个世界
>
> 天空之上的森林之中
>
> 等这场战争结束之后
>
> 不归之人与望眼欲穿之人
>
> 人人本着正义之名
>
> 长存不灭的过去，逐渐消逝的未来
>
> 我回来了
>
> 即使太阳终将坠落
>
> 即使无法看见未来
>
> 此时此刻的光辉
>
> 盼君勿忘
>
> 世界上最幸福的女孩子，珂朵莉

**如果幸福有颜色，那一定是被末日之红染尽的蓝色**

---

Phigros 真好玩喵，不过现在应该到瓶颈了，再加手疼和掉帧的 debuff，真踏马的难受喵

rks = 15.07

---

昨晚（11.28）妄想症系列出十重了喵！！！

> 一重加害
> 
> 二重变革
> 
> 三重爱恋
> 
> 四重罪孽
> 
> 五重空洞
> 
> 六重不忠
> 
> 七重痼病
> 
> 八重回归
> 
> 九重现实
> 
> 十重（后面忘了:(
> 
> ---
> 
> 三重恋爱
> 
> 零重祈愿
> 
> 泠重乞愿
> 
> ---
> 
> 自攻自受
> 
> 妄想 Paranoia
> 
> 妄想 Reality
> 
> ---
> 
> 第一首歌
> 
> 世界沉睡童话
> 
> 微观戏剧
> 
> 绝世丑角

---

出售 `E3-1231v3` CPU、`ASUS Z97-B` 主板、两条 `DDR3-1600 8G` 内存、`Google Pixel C` 平板（已刷 `Andriod 13 ArrowOS`）喵

有意者加我 QQ 喵：`3155172182`，验证信息 `RrAT17`
*/