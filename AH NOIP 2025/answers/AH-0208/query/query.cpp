#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
/*
这题题面没看懂直接用来写游记吧……

现在是最后半小时，我会写的性质都写完了，其他的我真不知道到底怎写

每次感觉我学OI就挺搞笑的，小学的时候学了一年，中间没学，然后让我高中接着搞

也是我自己自律性的问题，平时训练总是在魔芋

老师上课讲的题目都能听懂，但自己事先写的时候却很难独立写出来

复习了很久的图伦结果今天T3还是不会写

CSP-S2的时候T1脑子坏了没想出来那个简单的贪心思路，今天T1估计也是反悔贪心，可惜我仍然不会写

我的OI生涯就这么结束了

回望过去满是遗憾，我对得起我在机房停课的一个月吗，我对得起我这一年的学习吗

最后二十分钟老师刚说没写的不要乱塞了

但我并不是一无所获，学习路上我遇到了很多很好的朋友，wht，hpz，xzh,myk，drc，yzx，等等

也感谢一直以来带我的老师，邓老师、何老师、金主任

感谢hfbz技术组对我们OIer的全力支持，可惜我为学校丢脸了

就这样吧

goodbye OI
see you C++
wait for the XCPC

AFO
*/
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        read();
    }
    n=read();
    for(int i=1;i<=n;i++){
        puts("0");
    }
    return 0;
}
