#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main (){
    int userInput;
    cout << "MENU\n";
    cout << "Enter Your Login and Password";
    cout << "                                        \n\n";
    cout << "| Press 1 to LOGIN                       |" << endl;
    cout << "| Press 2 to REGISTER                    |" << endl;
    cout << "| Press 3 if you forgot your PASSWORD    |" << endl;
    cout << "| Press 4 to EXIT                        |" << endl;
    cout << "\nPress enter your choice:  ";
    cin >> userInput;
    
    switch(userInput){
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout << "\t\t\t Goodbye! \n\n";
        break;

        default:
        system("cls");
        cout << "Please select from options displayed \n" << endl;
        main();
    }
}

void login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "Please enter the username and password: " << endl;
    cout << "USERNAME ";
    cin >> userId;
    cout << "PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while(input >> id >> pass){
        if(id == userId && pass == password){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count == 1){
        cout << userId << "\n Your LOGIN was successful! \n";
        main();
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}

void registration(){
    string r_userId, r_password, r_id, r_pass;
    system("cls");
    cout << "Enter your USERNAME: ";
    cin >> r_userId;
    cout << "Enter your PASSWORD: ";
    cin >> r_password;

    if(r_password.empty()){
        cout << "You must set a password! \n";
        registration();
    }

    ofstream f1("records.txt", ios::app);
    f1 << r_userId << ' ' << r_password << endl;
    system("cls");
    cout << "\nYour REGISTRATION was successful! \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout << "You forgot your password? \n";
    cout << "| Press 1 to search your id by username    |" << endl;
    cout << "| Press 2 to return to main menu           |" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    switch(option){
        case 1:
        {
            int count = 0;
            string s_userId, s_id, s_pass;
            cout << "\n\t\t\t Enter your username to check id: ";
            cin >> s_userId;

            ifstream f2("records.txt");
            while(f2 >> s_id >> s_pass){
                if(s_id == s_userId){
                    count = 1;
                }
            }
            f2.close();
            if(count == 1){
                cout << "\n\n Your account was found! \n";
                cout << "\n\n Your password is: " << s_pass;
                main();
            } else {
                cout << "\n\t Sorry! Your account was not found! \n";
                main();
            }
            break;
        }

        case 2:
        {
            main();
        }

        default:
            cout << "\t\t\t Please select from options displayed \n" << endl;
            forgot();
    }
}