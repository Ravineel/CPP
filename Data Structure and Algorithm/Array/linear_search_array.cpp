#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[], int n,int k){

    for(int i=0;i<n;i++){
        if( a[i]==k){

            return i;
        }
    }

    return -1;
}


int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    int k;
    cin>>k;

    cout<<linear_search(a,n,k);

}