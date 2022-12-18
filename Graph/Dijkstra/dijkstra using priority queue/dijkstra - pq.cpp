#include<bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;
vector<int> dist(1000001, 1e9); //all nodes except src is infinity(a large number)
list<pair<int, int>> adj[1000001];

void dijkstra(int src)
{
    //initially distance of src is 0
    dist[src]=0;
    pq.push({0, src});

    while(!pq.empty()){
        int node=pq.top().second;//accessing current node
        pq.pop();//removing the current node from priority queue

        for (auto it=adj[node].begin();it!=adj[node].end();it++){
            int edgeWeight = (*it).first;
            int weight = (*it).second;

            ///relaxation
            if (dist[edgeWeight] > dist[node] + weight) {
                dist[edgeWeight] = dist[node] + weight;
                pq.push(make_pair(dist[edgeWeight], edgeWeight));
            }
        }
    }
}

int main()
{
    //# of nodes & edges
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v, w;
        //two nodes and their weight
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    dijkstra(0);

    cout<<"Vertex \tDistance from Source"<<endl;
    for (int i=0;i<n;i++)
        cout<<i<<"\t"<<dist[i]<<endl;

    return 0;
}

//sample input
//9 14
//0 1 4
//0 7 8
//1 2 8
//1 7 11
//2 3 7
//2 8 2
//2 5 4
//3 4 9
//3 5 14
//4 5 10
//5 6 2
//6 7 1
//6 8 6
//7 8 7
