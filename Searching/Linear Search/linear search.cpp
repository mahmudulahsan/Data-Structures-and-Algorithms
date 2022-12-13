#include<bits/stdc++.h>

using namespace std;

bool ls(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(x==a[i]){
            cout<<"found at "<<i+1<<endl;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n; cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x; cin>>x;
    int res;
    res = ls(a, n, x);

    if(!res) cout<<"not found"<<endl;

    return 0;
}
