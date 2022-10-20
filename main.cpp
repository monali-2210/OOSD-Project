#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

void DisplayMenu();
int security();

class Main_Manager_Railway{
    public:
        Main_Manager_Railway(){
            int k = security();
            DisplayMenu(k);
        }

};

int security(){
    int i, j = 0;
    char user_data[8], user_input[8], pwd_data[8], pwd_input[8];
    cout<<"\tPlease enter your credentials below\n";
    cout<<"\t Username : ";
    cin>>user_input;
    cout<<"\t Password : ";
    cin>>pwd_input;
    ifstream userin;
    ifstream pwdin;
    userin.open("Username.txt", ios::out);
    pwdin.open("password.txt", ios::out);
    while(! userin.eof()){
        userin.getline(user_data, 8);
        pwdin.getline(pwd_data, 8);

        for(int i = 0; user_data[i]!='\0'; i++){
            if(user_data[i]==user_input[i] && pwd_data[i]==pwd_input[i]){

            }else{
                cout<<"Username and password didn't match!\n";
                j++;
                break;
            }
        }
    }
    return j;
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
                   cin>>choice;
                   switch(choice){
                    case 1:create_new();
                        break;
                    case 2:modify_route();
        				break;
        			case 3:show_route();
        				break;
        			case 4:del_route();
        				break;
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