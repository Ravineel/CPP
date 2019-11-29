#include<iostream>
#include<map>

using namespace std;

int main(){
 map <string,int> days;
 days.insert({"Monday",1});
 days.insert({"Tuedsay",2});
 days.insert({"Wednesday",3});
 days.insert({"Thursday",4});
 days.insert({"Friday",5});
 days.insert({"Saturday",6});
days.insert({"Sunday",7});

string s;
cin>>s;

cout<<days[s];
 




    return 0;
}