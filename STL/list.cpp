#include<iostream>
#include<list>
#include<algorithm>

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
        List1.push_back(x);
    }

    //to find value in list, find[first,last,value) 

    int x ;
    cin>>x;
    list<int> :: iterator it = find(List1.begin(),List1.end(),x);
    //it will have the position to the element

    // to reverse a list

    List1.reverse();

    //to sort a list

    List1.sort();

    /*and many more functions
    List1.splice();
    List1.empty();
    List1.erase();
    List1.pop_back();
    List1.pop_front();
    List1.size();
    List1.unique();
    List1.swap();
    List1.merge();
    List1.resize();
    List1.clear()
    etc....
    */


    return 0;
}