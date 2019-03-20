#include <iostream>
#include "structs.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include "functions.h"
#include <vector>
#include "students.h"

using namespace std;

int get_nber_lines(std::string filename)
{
    ifstream file(filename.c_str());
    int i=0;
    std::string line;
    file.ignore();
    while (getline(file, line))
    {
        i++;
    }
    return i;
}
void display_file(std::string filename)
{
    ifstream level_list(filename.c_str());
    if (level_list)
    {
        std::string line;
        int i=1;
        while(getline(level_list, line))
        {
            cout << i << ". " << line << endl;
            i++;
        }
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}
std::string get_level(int number)
{
    ifstream level_list("files/levels.stu");
    if (level_list)
    {
        std::string line;
        for(int i=1; i!=number; i++)
        {
            getline(level_list, line);
        }
        getline(level_list, line);
        level_list.close();
        return line;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}
void add_level(std::string level_name)
{
    ofstream level_list("files/levels.stu", ios::out | ios::app);
    if (level_list)
    {
        level_list << level_name << endl;
        cout << "Level saved successfully" << endl;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}

void display_menu()
{
    cout << "    00       0   0      00 " << endl;
    cout << "   0  0      0   0     0  0" << endl;
    cout << "    0       0 0 0 0     0" << endl;
    cout << "      0     0 0 0 0       0" << endl;
    cout << "   0   0  0 0  0  0 0  0   0" << endl;
    cout << "     0     0   0   0     0" << endl << endl;
    cout << "8. BACK       9: MAIN MENU      0: EXIT" << endl << endl;
}
void control_choice(int &choice, int limit, int type)
{
    while((!(cin >> choice)) || (choice<0 || (choice>limit && choice<8) || choice>9))
    {
        if (type == 1)
        {
            cout << endl << "Wrong Entry! Select an option by typing its corresponding number: ";
        }
        else
        {
            cout << "Wrong Entry! Enter an integer between 1 and " << limit << ": ";
        }
        cin.clear();
        cin.ignore();
    }
}

//   Marks management
//--------------------------

int write_file(string filename, string data)
{


    return 0;
}

void display_options()
{
    cout << "Browse ..." << endl;
    cout << "----------------------" << endl << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Genie Logiciel" << endl;
    cout << "2. Systeme et poseaux" << endl;
    cout << "3. Software Engineering" << endl;
    cout << "   Choice: ";
}

void display_GL()
{
    cout << "Genie Logiciel" << endl;
    cout << "----------------------" << endl << endl;
    cout << "Choose a level: " << endl;
    cout << "1. Level 1" << endl;
    cout << "2. Level 2" << endl;
    cout << "3. Level 3" << endl;
    cout << "   Choice: ";
}

void display_SR()
{
    cout << "Systeme et Reseau" << endl;
    cout << "----------------------" << endl << endl;
    cout << "Choose a level: " << endl;
    cout << "1. Level 1" << endl;
    cout << "2. Level 2" << endl;
    cout << "3. Level 3" << endl;
    cout << "   Choice: ";
}

void display_GL1()
{
    cout << "Level 1 | Genie Logiciel" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. GL1A" << endl;
    cout << "2. GL1B" << endl;
    cout << "3. GL1C" << endl;
    cout << "   Choice: ";
}

void display_GL2()
{
    cout << "Level 2 | Genie Logiciel" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. GL2A" << endl;
    cout << "2. GL2B" << endl;
    cout << "   Choice: ";
}

void display_GL3()
{
    cout << "Level 3 | Genie Logiciel" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. GL3A" << endl;
    cout << "2. GL3B" << endl;
    cout << "3. GL3C" << endl;
    cout << "   Choice: ";
}

void display_SR1()
{
    cout << "Level 1 | Systeme et Reseaux" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. SR1A" << endl;
    cout << "1. SR1B" << endl;
    cout << "1. SR1C" << endl;
    cout << "   Choice: ";
}

void display_SR2()
{
    cout << "Level 2 | Systeme et Reseaux" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. SR2A" << endl;
    cout << "1. SR2B" << endl;
    cout << "1. SR2C" << endl;
    cout << "   Choice: ";
}

void display_SR3()
{
    cout << "Level 3 | Systeme et Reseaux" << endl;
    cout << "---------------------------------" << endl;
    cout << "Choose a class: " << endl;
    cout << "1. SR3A" << endl;
    cout << "1. SR3B" << endl;
    cout << "1. SR3C" << endl;
    cout << "   Choice: ";
}
void display_SE()
{
    cout << "Software Engineering" << endl;
    cout << "------------------------" << endl << endl;
    cout << "Choose a level: " << endl;
    cout << "1. Level 1" << endl;
    cout << "2. Level 2" << endl;
    cout << "   Choice: ";
}

string get_class()
{
    int choice;
    system("cls");
    display_menu();
    display_options();
    control_choice(choice, 3, 1);
    if (choice == 1)
    {
        system("cls");
        display_menu();
        display_GL();
        control_choice(choice, 3, 1);
        if(choice == 1)
        {
            system("cls");
            display_menu();
            display_GL1();
            control_choice(choice, 3, 1);
            if (choice == 1)
            {
                return "GL1A";
            }
            else if (choice == 2)
            {
                return "GL1B";
            }
            else if (choice == 3)
            {
                return "GL1C";
            }
            else if (choice == 8)
            {
                return "BACK";
            }
            else if (choice == 9)
            {
                return "HOME";
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        if(choice == 2)
        {
            system("cls");
            display_menu();
            display_GL2();
            control_choice(choice, 2, 1);
            if (choice == 1)
            {
                return "GL2A";
            }
            else if (choice == 2)
            {
                return "GL2B";
            }
            else if (choice == 3)
            {
                return "GL2C";
            }
            else if (choice == 8)
            {
                return "BACK";
            }
            else if (choice == 9)
            {
                return "HOME";
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        else if(choice == 3)
        {
            system("cls");
            display_menu();
            display_GL3();
            control_choice(choice, 2, 1);
            if (choice == 1)
            {
                return "GL3A";
            }
            else if (choice == 2)
            {
                return "GL3B";
            }
            else if (choice == 3)
            {
                return "GL3C";
            }
            else if (choice == 8)
            {
                return "BACK";
            }
            else if (choice == 9)
            {
                return "HOME";
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        else if(choice == 2)
        {
            system("cls");
            display_menu();
            display_SR;
            control_choice(choice, 3, 1);
            if(choice == 1)
            {
                system("cls");
                display_menu();
                display_SR1;
                control_choice(choice, 3, 1);
                if (choice == 1)
                {
                    return "SR1A";
                }
                else if (choice == 2)
                {
                    return "SR1B";
                }
                else if (choice == 3)
                {
                    return "SR1C";
                }
                else if (choice == 8)
                {
                    return "BACK";
                }
                else if (choice == 9)
                {
                    return "HOME";
                }
                else if(choice == 0)
                {
                    exit(0);
                }
            }
            else if(choice == 2)
            {
                system("cls");
                display_menu();
                display_SR2();
                control_choice(choice, 2, 1);
                if (choice == 1)
                {
                    return "SR2A";
                }
                else if (choice == 12)
                {
                    return "SR2B";
                }
                else if (choice == 1)
                {
                    return "SR2C";
                }
                else if (choice == 8)
                {
                    return "BACK";
                }
                else if (choice == 9)
                {
                    return "HOME";
                }
                else if(choice == 0)
                {
                    exit(0);
                }
            }
            else if(choice == 3)
            {
                system("cls");
                display_menu();
                display_SR3();
                control_choice(choice, 2, 1);
                if (choice == 1)
                {
                    return "SR3A";
                }
                else if (choice == 2)
                {
                    return "SR3B";
                }
                else if (choice == 3)
                {
                    return "SR3C";
                }
                else if (choice == 8)
                {
                    return "BACK";
                }
                else if (choice == 9)
                {
                    return "HOME";
                }
                else if(choice == 0)
                {
                    exit(0);
                }
            }
            else if (choice == 8)
            {
                return "BACK";
            }
            else if (choice == 9)
            {
                return "HOME";
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        if(choice == 3)
        {
            system("cls");
            display_menu();
            display_SE();
            control_choice(choice, 2, 1);
            if (choice == 1)
            {
                return "SE1";
            }
            else if (choice == 2)
            {
                return "SE2";
            }
            else if (choice == 8)
            {
                return "BACK";
            }
            else if (choice == 9)
            {
                return "HOME";
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        else if (choice == 8)
        {
            return "BACK";
        }
        else if (choice == 9)
        {
            return "HOME";
        }
        else if(choice == 0)
        {
            exit(0);
        }
    }
}
