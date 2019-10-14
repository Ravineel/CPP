#include<iostream>
#include<list>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Syntax :- list<data_type> variable_name
    list<int>List1;

    /* 
    to insert value into list, list_name.append(value)
    
    eg:-
    */

    int n;
    cin>>n;
   
    for(int i=0;i<n;i++)
    {   int x;
        cin>>x;
        List1.insert(x);
    }

    //to find value in list, find[first,last,value) 

    int x ;
    cin>>x;
    find(List1.begin(),List1.end(),x);

     

    return 0;
}