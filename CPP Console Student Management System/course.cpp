#include <iostream>
#include "course.h"
#include <fstream>
#include "structs"

using namespace std;

//      COURSE MANAGMENT
//--------------------------------
void save_course_list()
{
    ofstream course_list_file("files/courses.stu", std::ios::out | std::ios::app);
    if(course_list_file)
    {
        string course_name;
        cout << "Enter the name of the new course: ";
        cin.ignore();
        getline(cin, course_name);
        course_list_file << course_name << endl;
        cout << "Course saved in list" << endl;
    }
    else
    {
        cout << "ERROR OPENING \"files/courses.stu\"" << endl;
    }
}
void save_level_course(string class_filename, int course_ID, int coef)
{
    ofstream level_course(class_filename.c_str(), std::ios::out | std::ios::app);     //c_str()will give the filename for it to be opened
    if (level_course)
    {
        level_course << course_ID << endl;
        level_course << coef << endl;
        cout << "Course saved successfully!" << endl;
        cin.get();
    }
    else
    {
        cout << "ERROR OPENING " << class_filename << ".txt" << endl;
        cin.get();
    }
}
void createcourse()
{
    course new_course;
    cout << "Name: " << endl;
    cin.ignore();
    getline(cin, new_course.name);

    cout << "Coef " << endl;
    cin >> new_course.coef;

    cout << "Semester " << endl;
    cin >> new_course.semester;

    cout << "Level " << endl;
    cin >> new_course.level;

    ofstream course_file("files/courses.stu");
    if (course_file)
    {
        course_file << new_course.name << endl;
        course_file << new_course.coef << endl;
        course_file << new_course.semester << endl;
        course_file << new_course.level << endl;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}
