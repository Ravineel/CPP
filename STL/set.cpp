#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(){

    /*
    Set is a associative container, which stores
    data in sorted order, by default its ascending order.
    All data in set are unique. 
   Syntax: set<data_type> set_name;
    */

   set<int> A;

   //to get inport for n data in a set;

   int n;
   cin>>n;

   for (int  i = 0; i <n; i++)
   {
        int x;
        cin>>x;
        A.insert(x);

   }


/*
for set to store data in descening order
we do set<data_type,greater<data_type>> set_name
*/
set<int, greater<int>>a;

   


    return 0;
}