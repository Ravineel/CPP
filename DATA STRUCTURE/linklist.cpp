#include<bits/stdc++.h>

using namespace std;


typedef struct node{

    int data;
    struct node *next;
}node;

node *head=NULL, *top=NULL;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ch=0;
    do{
        cout<<"\nEnter 1 to insert into node ";
        cout<<"\nEnter 2 to delete an element ";
        cout<<"\nEnter 3 to search for an element ";
        cout<<"\nEnter 0 to exit ";
        cout<<"\nEnter choice: ";
        cin>>ch;
     
        cout<<"\n-------------------------------------------------------------------------------------------------------------\n";

        switch(ch){

            case 1: {
						cout<<"\t\t\tInsertion of Elements\n";
                    	int a;
                    	cout<<"Enter value: "; cin>>a;
                    	node *p = (node*)malloc(sizeof(node));
                    	p->data = a;
                    	p->next = NULL;
                    	if(head == NULL)
                        	head = top = p;
                    	else{
                         	top->next = p;
                        	top = p; 
                    	}
                    	cout<<"Element inseterd\n-------------------------------------------------------------------------------------------------------------\n";
                    	break;
                }

            case 2: {
						cout<<"\t\t\tDeleting Element \n";
                    	cout<<"Enter value to be deleted: ";
                    	int a;
                    	cin>>a; 
                    
                    
                    	if(head->data==a){   
							head=head->next;
                        	cout<"Element deleted\n-------------------------------------------------------------------------------------------------------------\n";     
                    
                        	break;
                    	}
                    	node *temp = head;
                    	node *t = NULL;
                    	while(temp->next!=NULL){   
							t=temp;
                        	if(temp->data = a && temp!=head)
                        		break;
                        
                        	temp=temp->next;
                    
                    	}   
                    	if(temp->next==NULL) cout<"Element could not be found\n-------------------------------------------------------------------------------------------------------------\n";
                    	else{
                            t->next=temp->next;
                       		cout<"Element deleted\n-------------------------------------------------------------------------------------------------------------\n";     
                    		}
                    	free(t);
                    	free(temp);
                    	break;
					}

            case 0:{
			}

            default:{
				cout<<"Wrong choice Entered\n";
				break;
			
			}          

        
        
        
        }
        

    }while(ch!=0);



    return 0;
}