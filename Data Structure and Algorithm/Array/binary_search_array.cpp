#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int l,int r,int k){

    if (l >= r){
        return -1;
    }

    
    int m = (l+r)/2;
    if (a[m]==k){
        return m;
    }
    else{

        if (a[m]>k){
            return binary_search(a,l,m-1,k);
        }
        else{
            return binary_search(a,m+1,r,k);
        }

    }

}


int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    int k;
    cin>>k;

    cout<<binary_search(a,0,n-1,k);

}