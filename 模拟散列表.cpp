#include<iostream>
#include<cstring>

using namespace std;
const int N=100003;        //N需要开到大于100000的第一个质数，这样冲突最少；
int h[N],e[N],ne[N],idx;

void Insert(int x)
{
    int k=(x % N + N) % N;   //哈希函数，+N再%N是为了让负数变为正数--c++中负数的模是负数
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}

bool find(int x)
{
    int k=(x % N + N) % N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);

    memset(h,-1,sizeof h);
    while(n--)
    {
        char op[2];     //scanf读字符串会过滤掉空格，用scanf读入单个字符建议用字符串
        int x;
        scanf("%s%d",op,&x);
        if(*op=='I') Insert(x);
        else 
        {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}


