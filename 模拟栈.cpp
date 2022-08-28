#include<iostream>
using namespace std;
const int N=100010;
int stk[N],tt,m;
int main()
{
    cin>>m;
    while(m--)
    {
        string op;
        int x;
        cin>>op;
        if(op=="push")
        {
            cin>>x;
             stk[++tt]=x;
        }
        if(op=="pop") tt--;
        if(op=="query") cout<<stk[tt]<<endl;
        if(op=="empty") 
        {
            if(tt==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}

