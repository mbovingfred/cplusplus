#include <iostream>
#include "students.h"
#include <fstream>
#include <vector>
#include "structs"
#include "functions.h"

using namespace std;

//      MANAGING STUDENT RECORDS
//****************************************
void get_student(student &new_student)
{
    cin.ignore();
    cout << "First Name(s): ";
    getline(cin, new_student.fname);

    cout << endl << "Second Name(s): ";
    getline(cin, new_student.secname);

    cout << endl << "Matricule: ";
    getline(cin, new_student.matricule);

    cout << endl << "Birthdate: ";
    cout << endl << "  Day: ";
    cin >> new_student.birthdate.day;

    cout << endl << "  Month: ";
    cin >> new_student.birthdate.month;

    cout << endl << "  Year: ";
    cin >> new_student.birthdate.year;

    cout << endl << "Sex: ";
    cin >> new_student.sex;

    cout << endl << "Level: ";
    cin >> new_student.level;

    cout << endl << "Class: ";
    cin >> new_student.classe;

    cin.ignore();
    int choice;
    cout << endl << "Option (choose) ";
    cout << endl << "     1. Genie Logiciel        2. Systeme et Reseaux       3. Software Engineering";
    cout << endl << " Choice:";
    control_choice(choice, 3, 1);
    if (choice == 1)
    {
        new_student.option = "Genie Logiciel";
    }
    else if (choice == 2)
    {
        new_student.option = "Systeme et Reseaux";
    }
    else if(choice == 3)
    {
        new_student.option = "Software Engineering";
    }
}

void save_student(student stu)
{
    ofstream student_file("files/students.stu", std::ios::out | std::ios::app);      // app means "append"
    if (student_file)
    {
        student_file << stu.fname << endl;
        student_file << stu.secname << endl;
        student_file << stu.matricule << endl;
        student_file << stu.birthdate.day << "/" << stu.birthdate.month << "/" << stu.birthdate.year << endl;
        student_file << stu.sex << endl;
        student_file << stu.level << endl;
        student_file << stu.classe << endl;
        student_file << stu.option << endl;
        student_file << 0 << endl;
        student_file << 'A' << endl;
        student_file.close();
        cout << "Student successfully saved" << endl;
        cin.get();
    }
    else
    {
        cout << "ERROR OPENING FILE " << endl;
        cin.get();
    }

}

void regist()
{
    student new_student;
    get_student(new_student);
    save_student(new_student);
}



void display_student(int student_pos)
{
    student stud;
    ifstream student_file("files/students.stu");
    string line;
    for (int i=1; i<student_pos; i++)
    {
        getline(student_file, line);
    }
    getline(student_file, line);
    cout << "First Name(s): " << line << endl;
    getline(student_file, line);
    cout << "Second Name(s): " << line << endl;
    getline(student_file, line);
    cout << "Matricule: " << line << endl;
    getline(student_file, line);
    cout << "Birthdate: " << line << endl;
    getline(student_file, line);
    cout << "Sex: " << line << endl;
    getline(student_file, line);
    cout << "Level: " << line << endl;
    getline(student_file, line);
    cout << "Class: " << line << endl;
    getline(student_file, line);
    cout << "Option: " << line << endl;
    getline(student_file, line);
    cout << "Hours of Absences: " << line << endl;
    getline(student_file, line);
    cout << "Conduct: " << line << endl;
}

int search_student(int filter, string value)
{
    int file_size = get_nber_lines("files/students.stu");
    ifstream student_file("files/students.stu", ios::in);
    if (student_file)
    {
        string got_value;
        for (int j=1; j<=filter; j++)
        {
            getline(student_file, got_value);
        }
        int i=3, pos=0;
        while(i<file_size && (got_value != value))
        {
            for (int j=1; j<=10; j++)
            {
                getline(student_file, got_value);
                i++;
            }
        }
        if(value == got_value)
        {
            pos = i-2;
        }
        student_file.close();
        return pos;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
        return 0;
    }
}

std::vector<int> search_students(int filter, string value)
{
    int file_size = get_nber_lines("files/students.stu");
    ifstream student_file("files/students.stu", std::ios::in);
    if (student_file)
    {
        std::vector<int> pos;
        string got_value;
        int i=1;
        for (int j=1; j<=filter; j++)
        {
            getline(student_file, got_value);
        }
        cout << "File size: " << file_size << endl;
        while(i<file_size)
        {
            if(value == got_value)
            {
                pos.push_back(i);
            }
            for (int j=1; j<=10; j++)
            {
                getline(student_file, got_value);
                i++;
            }

        }
        student_file.close();
        return pos;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}


int search_student()
{
    int choice;
    cout << "Choose filter for search: " << endl;
    cout << "1. Matricule" << endl;
    cout << "2. First Name" << endl;
    cout << "3. Second Name" << endl;
    while( (!(cin >> choice)) || choice>3 || choice<1)
    {
        cout << "Wrong entry! Please choose from 1 to 3: ";
        cin.clear();
        cin.ignore();
    }
   if (choice == 1)
    {
        string matricule;
        int student_pos;
        cout << "Enter the matricule: ";
        getline(cin, matricule);
        student_pos = search_student(3, matricule);
        if (student_pos == 0)
        {
            cout << "No student found with this matricule" << endl;
        }
        else
        {
            display_student(student_pos);
        }
        return student_pos;
     }
     else if (choice == 2)
     {
        string fname;
        std::vector<int> student_pos;
        cout << "Enter the First Name: ";
        getline(cin, fname);
        student_pos = search_students(1, fname);
        if (!(student_pos[0]))
        {
            cout << "No student found with this first name" << endl;
        }
        else
        {
            cout << student_pos.size() << " results were found !" << endl;
            for(int i=0; i<=student_pos.size(); i++)
            {
                display_student(student_pos[i]);
            }
        }
    }
    else if(choice == 3)
    {
        string secname;
        std::vector<int> student_pos;
        cout << "Enter the First Name: ";
        getline(cin, secname);
        student_pos = search_students(2, secname);
        if (!(student_pos[0]))
        {
            cout << "No student found with this second name" << endl;
        }
        else
        {
            int i=0;
            cout << student_pos.size() << " results were found !" << endl;
            while(student_pos[i])
            {
                display_student(student_pos[i]);
            }
        }
    }
}

/*void delete_entry(int pos)            //To be continued...
{
    ofstream temp_file("files/temp.stu");
    ifstream student_file("files/students.stu");
    student_file.ignore();
    string line;
    int i=1;
    while(getline(student_file), line)
    {
        if (i>=pos && i<=(pos+6))
        {
        }
        else
        {
            temp_file << line;
        }
    }
    temp_file.close();
    student_file.close();
    remove("files/students.stu");


}*/

/*void modify_student(int student_pos)
{
    int choice;
    cout << "Choose what is to be modified: " << endl;
    cout << "1. First Name" << endl;
    cout << "2. Second Name" << endl;
    cout << "3. Matricule" << endl;
    cout << "4. Birthdate" << endl;
    cout << "5. Sex" << endl;
    cout << "6. Level" << endl;
    cout << "7. Option" << endl;
    while( (!(cin >> choice)) || choice>7 || choice<1)
    {
        cout << "Wrong entry! Please choose from 1 to 7: ";
        cin.clear();
        cin.ignore();
    }
    switch(choice)
    {
        case 1:

    }
}*/
