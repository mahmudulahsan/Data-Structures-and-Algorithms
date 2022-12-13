#include<bits/stdc++.h>

using namespace std;

bool bs(int a[], int left, int right, int mid, int n, int x)
{
    if(left<=right){
        mid = (left + right) / 2;
        if(x == a[mid]){
            cout<<"found at "<<mid+1<<endl;
            return 1;
        }
        else if(x > a[mid]){
            left = mid + 1;
            bs(a, left, right, mid, n, x);
        }
        else if(x < a[mid]){
           right = mid - 1;
           bs(a, left, right, mid, n, x);
        }
    }
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

        int left = 0, right = n-1, mid = (left + right) / 2;
        bool res = 0;
        res = bs(a, left, right, mid, n,  x);
        if(!res) cout<<"not found"<<endl;
    }

    return 0;
}
