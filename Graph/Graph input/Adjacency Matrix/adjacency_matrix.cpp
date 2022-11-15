#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define mod       1e9+7
#define pi        acos(-1)
#define gcd(a,b)  __gcd(a,b)
#define lcm(a,b)  (a/__gcd(a,b))*b
#define pb        push_back
#define m_p       make_pair
#define mem(a,x)  memset((a),(x),sizeof(a))

#define endl      '\n'
#define nl        cout<<endl;
#define yes       cout<<"YES"<<endl
#define no        cout<<"NO"<<endl
#define gp       " "
#define SP(x,y)   setprecision((y))<<fixed<<(x)

#define fastio     ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

int a[1000][1000];

int main()
{
    //fastio
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        cout<<"node"<<i+1<<" is connected to: ";
        for(int j=0;j<n;j++){
            if(a[i][j])
                cout<<j+1<<" ";
        }nl;
    }

    return 0;
}

