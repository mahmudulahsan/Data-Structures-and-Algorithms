#include<bits/stdc++.h>

using namespace std;
//1 2 3 4 5 6 7 8 9 10
//0 2 1 3 4 5 6 7 8 9

bool bs(int a[], int n, int x)
{
    int left=0, right=n-1, mid= n/2;
    while(left<=right){
        if(a[mid]==x){
            cout<<"found at "<<mid+1<<endl;
            return 1;
        }
        else if(x>a[mid]){
            left=mid+1;
            mid=(right+left)/2;
        }
        else{
            right=mid-1;
            mid=(right+left)/2;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0 ; i<n ; i++)
        cin>>a[i];
    sort(a, a+n);

    while(1){
        int x;
        cin>>x;
        bool res = 0;
        res = bs(a, n, x);
        if(!res) cout<<"not found"<<endl;
    }

    return 0;
}
