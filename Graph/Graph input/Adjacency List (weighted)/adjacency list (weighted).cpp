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
vector<pair<int,int>>arr[MAX];
vector<pair<int,int>>cost[MAX];

int main()
{
    //fastio
    int n, m;
    //input highest node and total edges
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        arr[u].pb({v, w});
        arr[v].pb({u, w});
    }

    for(int i=0;i<n;i++){
        cout<<"node "<<i+1<<" is connected to : "<<endl;
        for(auto u: arr[i+1])
            cout<<"node : "<<u.first<<" weight : "<<u.second<<endl;
    }nl;nl;

    return 0;
}

//sample input
//6 7
//1 2 10
//1 4 30
//4 2 100
//2 5 20
//4 5 40
//5 3 50
//6 3 60

