#include<bits/stdc++.h>
using namespace std;

vector<int>v[100001];
bool vis[100001];

void dfs(int node)
{
    vis[node]=1;
    cout<<node<<" ";
    for(auto child:v[node]){
        if(!vis[child])
            dfs(child);
    }
}

int main()
{
    int n;
    //enter number of nodes
    cin>>n;

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //enter starting node
    int x;
    cin>>x;
    dfs(x);
    return 0;
}

//6
//1 2
//1 4
//4 2
//2 5
//4 5
//5 3
//6 3
