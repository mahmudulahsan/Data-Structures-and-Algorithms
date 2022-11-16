#include<bits/stdc++.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

//adjacency matrix
int adj[100][100];
int color[100];
int node, edge;

int Time = 1;
int d[100]; //discovery time
int f[100]; //finishing time

void dfsVisit(int x){
    color[x] = GRAY;
    d[x] = Time;
    Time++;

    for(int i=1;i<=node;i++){
        if(adj[x][i]){
           if(color[i]==WHITE){
              dfsVisit(i);
           }
        }
    }
    color[x] = BLACK;
    f[x] = Time;
    Time++;
}

void dfs(){
    for(int i=1;i<=node;i++){
        color[i] = WHITE;
    }
    for(int i=1;i<=node;i++){
        if(color[i] == WHITE){
            dfsVisit(i);
        }
    }


}

int main()
{
    ///graph input using adjacency matrix
    //# of nodes & edges
    cin>>node>>edge;

    int x, y;
    for(int i=1;i<=edge;i++){
        cin>>x>>y;
        adj[x][y] = 1;
        //adj[y][x] = 1;
    }

    dfs();

    ///Output graph
    for(int i=1;i<=node;i++){
        if(color[i] == BLACK){
            cout<<"Node: "<<i<<" "<<d[i]<<" "<<f[i]<<endl;
        }
    }


    return 0;
}

///Sample input
//6 7
//1 2
//1 4
//4 2
//2 5
//4 5
//5 3
//6 3
