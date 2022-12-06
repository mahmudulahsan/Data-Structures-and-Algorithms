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
int vis[MAX];
int level[MAX];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;

    cout<<"Current node\t"<<"Distance from source"<<endl;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<"\t\t"<<level[cur_v]<<endl;
        for(auto child : arr[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
}

int main()
{
    //fastio
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int u, v;
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }

    nl;
    bfs(1);

    return 0;
}

//sample input
//13
//1 2
//1 3
//1 13
//2 5
//5 6
//5 7
//5 8
//8 12
//3 4
//4 9
//4 10
//10 11
//9 11

//graph
//              1
//         /    |   \
//        2     3   13
//       /      |
//      5       4
//    / | \    / \
//   6  7  8  10  9
//          \  \  /
//          12  11
