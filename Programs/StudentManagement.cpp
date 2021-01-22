#include<bits/stdc++.h>
using namespace std;

class Student{
    protected:
        char name[30];
        char rollno[30];
        int marks[3];

    public:
        bool addData();
        bool checkData(char rollno[]);
        void displayData();
        bool upadteData(char s[], int mark, int ch,int code);
        int calculateData();
};

bool Student::addData(){

    try
    {
        cout<<"\nEnter name:";
        cin>>name;
        cout<<"\nEnter Roll no.: ";
        cin>>rollno;
        cout<<"\n-------Marks-----";
        cout<<"\nEnter Mark 1: ";
        cin>>marks[0];
        cout<<"\nEnter Mark 2: ";
        cin>>marks[1];
        cout<<"\nEnter Mark 3: ";
        cin>>marks[2];
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }   
    return false;
}

bool Student::checkData(char Rollno[]){

    try
    {
        return strcmp(rollno,Rollno)==0?true:false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return false;
}

void Student::displayData(){
        
        cout<<"\nName:";
        cout<<name;
        cout<<"\nRoll no.: ";
        cout<<rollno;
        cout<<"\n-------Marks-----";
        cout<<"\nMark 1: ";
        cout<<marks[0];
        cout<<"\nMark 2: ";
        cout<<marks[1];
        cout<<"\nMark 3: ";
        cout<<marks[2];
        
}

bool Student::upadteData(char s[]="", int mark=0, int ch=0,int code=-1 ){

    if(ch==1){
        try
        {
           strcpy(rollno,s);
           cout<<"\nrollno: "<<rollno;
           return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }        
    }
    if(ch==2){
        try
        {  
            strcpy(name,s);
           return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }        
    }
    if(ch==3){
        try
        {
           marks[code-1]=mark;
           return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }        
    }
    return false;
}

int Student::calculateData(){

}

void writeData(Student* st,int n){
    fstream file;
    file.open("Student.txt", ios::out | ios::in | ios::trunc);
    for(int i=0;i<n;i++){
            file.write((char *)&st[i], sizeof(st[i]));
    }
    file.close();
}

void readData(Student* st,int n){
    fstream file;
    file.open("Student.txt", ios::out | ios::in | ios::app);
    for(int i=0;i<n;i++){
            file.read((char *)&st[i], sizeof(st[i]));
        }
    file.close();
}

int countData(){
    int count=0;
    try{
        fstream file;
        file.open("Student.txt", ios::in);
        Student st;
        while(  file.read((char *)&st, sizeof(st)))
            { 
                count++;               
            }
            file.close();
    }catch(exception e){
        cout<<"\nError";
    }        
    return count;
}

int checkRoll(char Rollno[], Student* st,int n){
    int m=n,pos=-1;
    
        readData(st,n);
        for(int i=0;i<n;i++){
            if(st[i].checkData(Rollno)){
                n-=1;
                pos=i;
                break;    
            }
        }
    return m>n?pos:-1;   
}

void add_Data(){

    int n;
    cout<<"\nEnter total students to be added: ";
    cin>>n;
    try{

        Student st[n];
        fstream file;

        file.open("Student.txt", ios::out | ios::in | ios::app);
        
        for(int i=0;i<n;i++){
            if(st[i].addData()){
                file.write((char *)&st[i], sizeof(st[i]));
                cout<<"\n Data Added";
            }
            else{
                cout<<"\ndata not added for "<<i<<"th student";
            }
        }

        cout<<"\n------Done------\n";
        file.close();
    }catch(exception e){
        cout<<"\nUnsuccessful";
    }

}



void delete_Data(){
    
    try{
        char Rollno[30];    
        cout<<"\nEnter Roll no: ";
        cin>>Rollno;
        int n= countData();
        Student st[n];
        fstream file;     
        
        int pos= checkRoll(Rollno,st,n);

        if(pos!=-1){
            if(pos==n-1)n--;
            else {
                st[pos]= st[pos+1];
                n--;
            }
        }else{
            cout<<"\nStudent Not Found";
        }

        writeData(st,n);
        
        cout<<"\n------Done------\n";
    }catch(exception e){
        cout<<"\nUnsuccessful";
    }
}

void display_Data(){
    
    try{
        fstream file;
        file.open("Student.txt", ios::out | ios::in | ios::app);
        Student st;
       
        int n=0;
        while(  file.read((char *)&st, sizeof(st)))
            { 
                n++;
                st.displayData();
            }
        if(n==0)cout<<"\nNo Student Data";

        cout<<"\n------Done------\n";

    }catch(exception e){
        cout<<"\nUnsuccessful";
    }
}



void update_Data(){
    
    
    int n = countData();
    char Rollno[30];
    Student st[n];
    cout<<"\nEnter Rollno that is needed to be modified: ";
    cin>>Rollno;
    int pos = checkRoll(Rollno, st, n);
    if(pos!=-1){
        int ch=0;
        cout<<"\nEnter 1 to change Rollno";
        cout<<"\nEnter 2 to change name";
        cout<<"\nEnter 3 to change mark";
        cout<<"\nEnter 0 to exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"\nEnter new Rollno: ";
            char newRoll[30];
            cin>>newRoll;
            st[pos].upadteData(newRoll,0,ch)?cout<<"\nSuccessful":cout<<"\nUnsuccessful";
            writeData(st,n);
            break;
        case 2:
            cout<<"\nEnter new name: ";
            char newName[30];
            cin>>newName;
            st[pos].upadteData(newName,0,ch)?cout<<"\nSuccessful":cout<<"\nUnsuccessful";
            writeData(st,n);
            break;
        case 3:
            cout<<"\nEnter Subject Code(1,2 or 3): ";
            int code,newMark;
            cin>>code;
            cout<<"\nEnter the new mark: ";
            cin>>newMark;
            st[pos].upadteData("",newMark,ch,code)?cout<<"\nSuccessful":cout<<"\nUnsuccessful";
            writeData(st,n);
            break;
        
        default:
            break;
        }
        
        

    }else{
        cout<<"\nNo Student found with Roll no: "<<Rollno;
    }
    cout<<"\n------Done------\n";


}

void calculate_Data(){

    try{

    }catch(exception e){
        cout<<"\nUnsuccessful";
    }
} 

int main(){

    int ch=1;
    do{
        cout<<"\n-------------------------";
        cout<<"\nEnter 1 to Add students";
        cout<<"\nEnter 2 to Delete a student";
        cout<<"\nEnter 3 to Dispaly students";
        cout<<"\nEnter 4 to update a student";
        cout<<"\nEnter 5 to Calculate marks for a student";
        cout<<"\nEnter 0 to exit";
        cout<<"\nEnter Choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            add_Data();
            break;
        case 2: 
            delete_Data();
            break;
        case 3:
            display_Data();
            break;
        case 4: 
            update_Data();
            break;
        case 5: 
            calculate_Data();
            break;
        case 0: break;
        
        default:cout<<"\nWrong Choice!";
            break;
        }

    }while(ch!=0);
    return 0;
}
