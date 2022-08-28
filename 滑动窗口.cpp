#include<iostream>
using namespace std;
const int N=1000010;
int n,k;
int a[N],q[N];  //q序列存储的是下标，最小值为q[hh]，但需先保证q[hh]在窗口中，且维护序列
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int hh=0,tt=-1;   //hh队头在左端，tt队尾在右端
    for(int i=0;i<n;i++)
    {
        //一般下一行为while，但这道题窗口一次只滑动一格，所以if也是OK的
        if(hh<=tt&&i-k+1>q[hh]) hh++; //i-k+1为窗口左端点,i-k+1>q[hh]说明当前q[hh]不在窗口中
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;  //队尾大于当前a[i]，队尾没有输出机会，出队（维护序列单调性）
        q[++tt]=i; //先将i写入,i可能为答案(在上一步判断中i足够小,将序列清空,使得i为q[hh])
        if(i>=k-1) printf("%d ",a[q[hh]]); //窗口满了才能输出
    }
    puts("");
    hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);
    }
    return 0;
}

