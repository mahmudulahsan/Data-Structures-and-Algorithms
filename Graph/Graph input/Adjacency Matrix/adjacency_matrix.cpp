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

    ///Enter number of nodes and edges
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        a[x][y]=w;
        a[y][x]=w;
    }

    for(int i=1;i<=n;i++){
        cout<<"node "<<i<<" is connected to: ";
        for(int j=0;j<n;j++){
            if(a[i][j])
                cout<<j<<" ";
        }nl;
    }

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

