#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m;
int h[N],size1;
void down(int u)
{
    int t=u;
    if(u*2<=size1  &&  h[u*2]<=h[t]) t=2*u;
    if(u*2+1<=size1  &&  h[u*2+1]<=h[t]) t=2*u+1;
    if(t!=u)
    {
        swap(h[t],h[u]);
        down(t);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    size1=n;
    for(int i=n/2;i;i--) down(i);
    while(m--)
    {
        printf("%d ",h[1]);
        h[1]=h[size1];
        size1--;
        down(1);
    }
    return 0;
}

