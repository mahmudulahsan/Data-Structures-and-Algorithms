#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>>pq;
    int t=7;
    while(t--){
        int a, b;
        cin>>a>>b;
        pq.push(make_pair(a, b));
    }
    cout<<endl;
     while(!pq.empty()){
        int f=pq.top().first, s=pq.top().second;
        pq.pop();
        cout<<f<<" "<<s<<endl;
    }

    return 0;
}
