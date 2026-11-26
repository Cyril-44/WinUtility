#include<iostream>
#include<algorithm>
using namespace std;
int n,i,j,k=1e9,num1,l,f1,f2,a1,a2,f3;
double k1=1000000001;
long long m;
int w[100001],w1[100011],f[100010];
int min1(int a,int b)
{
    if(a>=b) return b;
     return a;
}
int max1(int a,int b)
{
    if(a>=b) return a;
     return b;
}
void wu(int i,long long m,int l)
{
    int b;
    if(f[i]==1) b=w[i];
    else b=w1[i];
    if(m<k||i>=n){
        num1=max1(l,num1);
        return ;
    }
    if(m-b>=0)
    {
    f[i]=f[i]*-1;
    wu(i,m-b,l+1);
    f[i]=f[i]*-1;
    }
    wu(i+1,m,l);
}
int main()
{
   freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    f1=1;
    f2=1;
    f3=1;
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>w1[i];
        if(w[i]!=w1[i]) f1=0;
        if(w[i]>w1[i]) f2=0;
        if(w[i]<w1[i]) f3=0;
        k=min1(k,min1(w[i],w1[i]));
        if((w[i]+w1[i])/2>k1){
            a1=i;
        }
        k1=min1(k1,(w[i]+w1[i])/2);
        f[i]=1;
    }
        if(f1==0&&f3==0&&f2==0||n<1000)
        wu(0,m,0);
        else if(f1==1) {
            j=int(k);
            num1=m/j;
        }
        else if(f3==1)
        {
            k1=k1*2;
            j=int(k1);
            num1=m/j*2;
        }
        else if(f2==1)
        {
            if(n<1000){
                wu(0,m,0);
                cout<<num1;
                return 0;
            }
            w[a1]=0;
            sort(w,w+n);
            for(i=0;i<n;i++)
            {
                while(w[i]==0&&i<n) i++;
                if(i>=n)  break;
                if(double(w[i])>k1||w[i]>m)
                    break;
                else {
                    m-=w[i];
                    num1++;
                }
            }
            num1+=m/int(k1*2)*2;
        }
        cout<<num1;
        return 0;
}
