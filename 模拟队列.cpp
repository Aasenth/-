#include<iostream>
using namespace std;
const int N=100010;
int q[N],hh,tt=-1,m;
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
            q[++tt]=x;
        }
        if(op=="pop") hh++;
        if(op=="empty") 
        {
            if(hh<=tt) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        if(op=="query") cout<<q[hh]<<endl;

    }
    return 0;
}
