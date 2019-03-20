#include <iostream>
#include "account.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//      MANAGING ACCOUNT
//--------------------------------
void modify_username()
{
    string username;
    cout << "Enter new username: ";
    cin.ignore();
    getline(cin, username);
    ofstream account_file("files/account.stu", std::ios::out | std::ios::ate);
    if (account_file)
    {
        account_file.seekp(0, std::ios::beg);
        account_file << username;
        account_file.close();
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}

void modify_password()
{
    string password;
    cout << "Enter new password: ";
    cin.ignore();
    getline(cin, password);
    fstream account_file("files/account.stu", std::ios::ate);
    if (account_file)
    {
        string line;
        account_file.ignore();
        getline(account_file, line);
        account_file << password;
        account_file.close();
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}






void create_account()
{
    ofstream new_account("files/account.stu", std::ios::out | std::ios::app);
    if(new_account)
    {
        string temp_string;
        cout << "Username: " << endl;
        cin.ignore();
        getline(cin, temp_string);
        new_account << temp_string << endl;

        cout << "Password: " << endl;
        getline(cin, temp_string);
        new_account << temp_string << endl;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}
