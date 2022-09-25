#include<iostream>
using namespace std;
const int N=100010;
int a[N],q[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)  q[i]=q[i-1]+a[i];
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",q[r]-q[l-1]);
    }
    return 0;
}

