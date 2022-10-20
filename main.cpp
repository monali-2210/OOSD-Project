#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

void DisplayMenu(int);
int admin_login();

class Main_Manager_Railway{
    public:
        Main_Manager_Railway(){
            int k = admin_login();
            DisplayMenu(k);
        }

};

int admin_login(){
    int i, j = 0;
    string user_data, user_input, pwd_data, pwd_input;
    cout<<"\tPlease enter your credentials below\n";
    cout<<"\t Username : ";
    cin>>user_input;
    cout<<"\t Password : ";
    cin>>pwd_input;
    ifstream userin;
    ifstream pwdin;
    pwdin.open("Password.txt", ios::out);
    userin.open("Username.txt", ios::out);
    while(! userin.eof()){
        getline(pwdin, pwd_data);
        getline(userin, user_data);
    }
    if(user_data == user_input && pwd_data == pwd_input){
        cout<<"\n\tSuccessfully Logged in!";
    }
    else{
        j++;
        cout<<"\n\tBad credentials!";
    }
    return j;
}

int user_check(string user, string pwd){
    string user_data, pwd_data;
    ifstream userin;
    ifstream pwdin;
    userin.open("user.txt", ios::out);
    pwdin.open("pass.txt", ios::out);
    while(!userin.eof()){
        getline(userin, user_data);
        getline(pwdin, pwd_data);
        if(user_data == user && pwd_data == pwd){
            return 0;
        }
        else{
            
        }
    }
    return 1;
}

void create_user(){
    char c = 'y';
    string user, pwd;

    
    while(c == 'y' || c == 'Y'){
        D: cout<<"\nEnter New Username : ";
           cin>>user;
           cout<<"\nEnter Password : ";
           cin>>pwd;
           if(user_check(user, pwd) != 0){
                ofstream userout;
                ofstream pwdout;
                userout.open("user.txt", ios::app);
                pwdout.open("pass.txt", ios::app);
                userout<<"\n"<<user;
                pwdout<<"\n"<<pwd;
                cout<<"User added successfully!";
                userout.close();
                pwdout.close();
                cout<<"\nAnother new user(y/n): ";
                cin>>c;
           }
           else{
                cout<<"\nUsername already exists!"; goto D;
           }
    }
    DisplayMenu(0);
}

void modify_user(){

}

void show_user(){
    string user, pwd;
    int i = 0;
    ifstream userin;
    ifstream pwdin;
    userin.open("user.txt", ios::out);
    pwdin.open("pass.txt", ios::out);
    cout<<"\tUSERNAME\tPASSWORD\n";
    while(!userin.eof()){
        i++;
        getline(userin, user);
        getline(pwdin, pwd);
        cout<<i<<"\t"<<user<<"\t\t"<<pwd<<endl;
    }
}

void delete_user(){

}

void DisplayMenu(int j){
    if(j == 0){
        int choice = 0;
        A: cout<<"\n\t 1. Users Menu";
           cout<<"\n\t 2. Main Menu";
           cout<<"\n\t Choose one of the above option : ";
           cin>>choice;

           if(choice == 1){
            choice = 0;
            B : cout<<"\n\t 1. Create New Users";
                cout<<"\n\t 2. Modify Existing Users";
                cout<<"\n\t 3. Show Users";
                cout<<"\n\t 4. Delete User";
                cout<<"\n\t 5. Previous Menu";
                cout<<"\n\t Choose one of the above option : ";
                cin>>choice;
                switch(choice){
                    case 1:create_user();
                        break;
                    case 2:modify_user();
                        break;
                    case 3:show_user();
                        break;
                    case 4:delete_user();
                        break;
                    case 5:goto A;
                        break;
                    default:cout<<"Invalid selection! Try again!!";
                            goto B;
                }
           }
           else if(choice == 2){
                choice = 0;
                C: cout<<"\n\t 1. Create New Route";
                   cout<<"\n\t 2. Modify Existing Route";
                   cout<<"\n\t 3. Show Routes";
                   cout<<"\n\t 4. Delete Routes";
                   cout<<"\n\t 5. Previous Menu";
                   cout<<"\n\t Choose one of the above option : ";
                   cin>>choice;
                   switch(choice){
                    // case 1:create_new();
                    //     break;
                    // case 2:modify_route();
        			// 	break;
        			// case 3:show_route();
        			// 	break;
        			// case 4:del_route();
        			// 	break;
                    case 5:goto A;
                        break;
                    default: cout<<"Invalid selection! Try again!!";
                             goto C;
                   }
           }
           else{
                cout<<"Invalid selection! Try again!!";
                goto A;
           }
    }
}

int main(){
    Main_Manager_Railway Obj1;
    return 0;
}