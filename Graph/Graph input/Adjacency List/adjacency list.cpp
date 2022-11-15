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

#define MAX 100000
vector<int>arr[MAX];
vector<int>cost[MAX];

int main()
{
    //fastio
    int n, m;
    ///input highest node and total edges
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }

    for(int i=0;i<n;i++){
        cout<<"node"<<i+1<<" is connected to : ";
        for(auto u: arr[i+1])
            cout<<u<<gp;
        nl;
    }

    return 0;
}

