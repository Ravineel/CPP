#include<bits/stdc++.h>

using namespace std;


typedef struct node{

    int data;
    struct node *next;
}node;

node *head=NULL;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ch=0;
    do{
        cout<<"\nEnter 1 to insert into node ";
        cout<<"\nEnter 2 to delete an element ";
        cout<<"\nEnter 3 to search for an element ";
        cout<<"\nEnter 0 to exit ";
        cout<<"Enter choice: ";
        cin>>ch;
        time(100)
        cout<<"\n-------------------------------------------------------------------------------------------------------------\n";

        switch(ch){

            case 1: cout<<"\t\t\tInsertion of Elements\n";
                    int a;
                    cout<<"Enter value: "; cin>>a;
                    node *p = (node*)malloc(sizeof(node));
                    p->data = a;
                    if(head == NULL)
                        head = p;
                    else
                      

        
        
        
        }
        

    }while(ch!=0);



    return 0;
}