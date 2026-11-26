#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[50005];
int L,R;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>L>>R;
        for(int o=1;o<=n;o++){
            int maxp=
            for(int j=L;j<=R;j++){
                int maxz=-0x7fffffff;
                for(int z=1-j;z<=n;z++){
                    if(z+j<o||z>o) continue;
                    int ans=0;
                    for(int c=z;c<=z+j;c++){
                        if(c<=0)continue;
                        ans+=a[c];
                    }
                    maxz=max(maxz,ans);
                }

            }
        }
    }
    return 0;
}
/*

炸了 后面三道都不会写 就这样吧
卡车丢失.jpg

大梦一场的董二千先生～
推开窗户举起望远镜～
眼底映出一阵浓烟～
前已无通路后不见归途～
*一阵激烈的小号声

渔王还想 继续做渔王～
可海港已经 不知去向～
此刻他醉倒 在洗浴中心 没有潮汐的梦～
胸口已暮色苍茫～～～～

中间忘了

独角大盗 百万富翁 摸爬滚打～
黑暗好像 一颗巨石 按在胸口～

我想要说的前人都已说过了！
我想要做的有钱人都做过了！
我想要的公平都是不公们虚构的～！
*一阵激烈的吉他声
                /爱|爱|爱|爱\         /ou
病名为爱--爱\    /            >一爱|爱一
           >爱/                           爱-爱-爱-爱....
                /爱|爱|爱|爱\         /ou
病名为爱--爱\    /            >一爱|爱一
           >爱/                           爱-爱-爱-爱....

考完了可以去打乌蒙 开心

大概率要退役了

你好我是无理亦想 ILLusi0n
请看到的你和我交朋友

*转身向山里走去

*/
