#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <sstream>
#include <fstream>
#include "account.h"
#include "course.h"
#include "files.h"
#include "students.h"
#include "functions.h"
#include "marks.h"

using namespace std;

int main()
{
    system("color 1F");

    //      HOME PAGE
    //*************************
    int choice;
    home:
    cout << "==============================================================================================================" << endl;
    cout << "                                 000          00   00           000" << endl;
    cout << "                                0   0         00   00          0   0" << endl;
    cout << "                               0     0        00   00         0     0" << endl;
    cout << "                                0            0  0 0  0         0" << endl;
    cout << "                                 `0          0  0 0  0          `0" << endl;
    cout << "                                   `0        0  0 0  0            `0" << endl;
    cout << "                                     `0     0    0    0             `0" << endl;
    cout << "                              0       0     0    0    0       0      0" << endl;
    cout << "                               0     0   0  0    0    0  0     0    0" << endl;
    cout << "                                 000      00           00        000" << endl;
    cout << "                                             STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "===============================================================================================================" << endl;
    cout << "MAIN MENU" << endl;
    cout << "------------------" << endl << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Manage database" << endl;
    cout << "2. Manage marks" << endl;
    cout << "3. Search student" << endl;
    cout << "4. Generate transcript" << endl;
    cout << "5. Alerts" << endl;
    cout << "6. Settings " << endl << endl;
    cout << "7. About" << endl;
    cout << "0. Exit" << endl;
    cout << "       Choice: ";
    control_choice(choice, 6, 1);
    if (choice == 1)        //MANAGE DATABASE
    {
        system("cls");
        display_menu();
        cout << "Manage Database" << endl;
        cout << "----------------------" << endl << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Record new students" << endl;
        cout << "2. Manage course records" << endl << endl;
        cout << "       Choice: ";
        control_choice(choice, 2, 1);
        if (choice == 1)
        {
            system("cls");
            display_menu();
            regist();
        }
        else if (choice == 2)
        {
            course:
            system("cls");
            display_menu();
            cout << "Course Management" << endl;
            cout << "-------------------------" << endl;
            cout << "Choose an option:" << endl;
            cout << "1. Record new course" << endl;
            cout << "2. Add a course level" << endl;
            cout << "3. Attribute a course to a class" << endl;
            cout << "4. Delete an existing course" << endl;
            cout << "\tChoice: " << endl;
            control_choice(choice, 5, 1);
            if (choice == 1)        //new course
            {
                choice = 1;
                string course_name;
                while(choice == 1)
                {
                    system("cls");
                    display_menu();
                    cout << "Available courses are as follows: " << endl;
                    display_file("files/courses.stu");
                    cout << endl;
                    cout << "After saving a course, type \"1\" to save more courses or \"2\" to stop saving" << endl;
                    save_course_list();
                    control_choice(choice, 2, 1);
                }
                if ((choice == 2) || (choice == 8))
                {
                    goto course;
                }
                else if (choice == 9)
                {
                    system("cls");
                    goto home;
                }
                else if(choice == 0)
                {
                    exit(0);
                }
            }
            else if(choice == 2)    // add course level
            {
                system("cls");
                display_menu();
                cout << "Available levels are as follows: " << endl;
                display_file("files/levels.stu");
                string course_name;
                cout << endl << "\tPlease enter the name of the new course level: ";
                cin.ignore();
                getline(cin, course_name);
                add_level(course_name);
                cin.get();
                goto course;
            }
            else if(choice == 3)    //attribute course level to class
            {
                system("cls");
                display_menu();
                cout << "Available levels are as follows: " << endl;
                display_file("files/levels.stu");
                cout << endl << "\tChoose a level using its corresponding number: ";
                cin >> choice;
                string level_name;
                int coef;
                level_name = get_level(choice);
                cout << "You choosed: " << level_name << endl;
                cout << "Available courses are as follows: " << endl;
                display_file("files/courses.stu");
                cout << endl << "\tChoose a course using its corresponding number: ";
                control_choice(choice, get_nber_lines("files/courses.stu"), 2);
                cout << "Enter the coeficient of this course: ";
                control_choice(coef, 15, 2);
                save_level_course("files/"+level_name+".stu", choice, coef);
                cout << "Press Enter to continue...";
                cin.get();
                goto course;
            }
            /*else if (choice == 4)   //modify an existing course
            {
                system("cls");
                display_menu();

            }*/
            else if (choice == 4)   //delete an existing course
            {
                delete_course:
                system("cls");
                display_menu();
                cout << "Delete a course" << endl;
                cout << "-------------------------" << endl;
                cout << "Choose an option:" << endl;
                cout << "1. Delete from course list" << endl;
                cout << "2. Delete from level" << endl;
                cout << "   Choice: ";
                control_choice(choice, 2, 1);
                if (choice == 1)
                {
                    system("cls");
                    display_menu();
                    cout << "Available courses are as follows: " << endl;
                    display_file("files/courses.stu");
                    cout << endl << "\tChoose a course to be deleted using its corresponding number: ";
                    control_choice(choice, get_nber_lines("files/courses.stu"), 2);
                    delete_line("files/courses.stu", choice);
                    cout << "Course successfully deleted" << endl;
                    cout << "Press Enter to continue...";
                    cin.get();
                    cin.get();
                    goto delete_course;
                }
                else if(choice == 2)
                {
                    system("cls");
                    display_menu();
                    cout << "Available levels are as follows: " << endl;
                    display_file("files/levels.stu");
                    int nber_lines, res;
                    nber_lines = get_nber_lines("files/levels.stu");
                    cout << endl << "\tChoose a level using its corresponding number: ";
                    control_choice(choice, nber_lines, 2);
                    res = delete_line("files/levels.stu", choice);
                    if (res == 0)
                    {
                        cout << "Level successfully deleted" << endl;
                    }
                    else
                    {
                        cout << "Level not deleted" << endl;
                    }
                }
            }
            else if (choice == 8)
            {
                system("cls");
                goto home;
            }
            else if (choice == 9)
            {
                system("cls");
                goto home;
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        else if (choice == 8)
        {
            system("cls");
            goto home;
        }
        else if (choice == 9)
        {
            system("cls");
            goto home;
        }
        else if(choice == 0)
        {
            exit(0);
        }
    }
    else if(choice == 2)    //MANAGE MARKS
    {
        system("cls");
        display_menu();
        string classe;
        classe = get_class();
    marks:
        system("cls");
        display_menu();
        int period;
        cout << "Marks management" << endl;
        cout << "----------------------" << endl;
        cout << "Choose an option: " << endl;
        cout << "1. Register CA1" << endl;
        cout << "2. Register CA2" << endl;
        cout << "3. Register Semester 1" << endl;
        cout << "4. Register Semester 2" << endl;
        cout << "5. Display marks" << endl;
        control_choice(period, 5, 1);
        system("cls");
        if (period != 5)
        {
            if (classe == "GL1A")
            {
                string classname = "GL1A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;
                vector<int> students = search_students(7, "GL1A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL1B")
            {
                string classname = "GL1B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL1B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL1C")
            {
                string classname = "GL1C";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL1C");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL2A")
            {
                string classname = "GL2A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL2A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL2B")
            {
                string classname = "GL2B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL2B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL2C")
            {
                string classname = "GL2C";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL2C");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL3A")
            {
                string classname = "GL3A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL3A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            if (classe == "GL3B")
            {
                string classname = "GL3B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL3B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "GL3C")
            {
                string classname = "GL3C";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/GL3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/GL3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "GL3C");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR1A")
            {
                string classname = "SR1A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR1A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR1B")
            {
                string classname = "SR1B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR1B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR1C")
            {
                string classname = "SR1C";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR1C");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR2A")
            {
                string classname = "SR2A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR2A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR2B")
            {
                string classname = "SR2B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR2B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR2C")
            {
                string classname = "SR2A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR2.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR2A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR3A")
            {
                string classname = "SR3A";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR3A");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR3B")
            {
                string classname = "SR3B";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR3B");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SR3C")
            {
                string classname = "SR3C";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SR3.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SR3C");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SE1")
            {
                string classname = "SE1";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SE1.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SE1.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SE1");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "SE2")
            {
                string classname = "SE2";
                cout << "---------------------------------" << endl;
                cout << "List of courses for this class: " << endl;
                string temp_string, filename = "files/SR3.stu";
                int course_id, i=1;
                while(i<=get_nber_lines(filename))
                {
                    temp_string = get_line(filename, i);
                    stringstream(temp_string) >> course_id;
                    cout << "1. " << get_line("files/courses.stu", course_id) << endl;
                    i+=2;
                }
                cout << "\t Your choice: ";
                control_choice(choice, get_nber_lines(filename)/2, 2);
                string coef;
                coef = get_line("files/SE2.stu", (2*choice));
                cout << "choice: " << choice << endl << "coef: " << coef << endl;

                vector<int> students = search_students(7, "SE2");
                string coursename = get_line("files/courses.stu", course_id);
                save_marks(coursename, students, coef, classname, period);
            }
            else if (classe == "BACK")
            {
                system("cls");
                goto home;
            }
            else if (classe == "HOME")
            {
                system("cls");
                goto home;
            }
        }
        else    //Display marks
        {
            system("cls");
            display_marks(classe);
            cin.get();
            goto marks;
        }
    }
    else if(choice == 3)    //SEARCH STUDENTS
    {
        search_student:
        system("cls");
        display_menu();
        cout << "Search student in database" << endl;
        cout << "---------------------------------" << endl << endl;
        cout << "Choose a filter: " << endl;
        cout << "1. by Matricule" << endl;
        cout << "2. by First Name" << endl;
        cout << "3. by Second Name" << endl;
        cout << "   Choice: ";
        control_choice(choice, 3, 1);
        int pos;
        if(choice == 1)
        {
            string matricule;
            cout << "Enter the matricule to be searched: ";
            cin.ignore();
            getline(cin, matricule);
            pos = search_student(3, matricule);
            system("cls");
            display_menu();
            if(pos == 0)
            {
                cout << "No student found with this matricule" << endl;
            }
            else
            {
                cout << "1 result found!" << endl;
                display_student(pos);
            }
        }
        else if(choice == 2)
        {
            string fname;
            cout << "Enter the first name to be searched: ";
            cin.ignore();
            getline(cin, fname);
            vector<int> poss = search_students(1, fname);
            if (poss.size() == 0)
            {
                cout << "No student found with this first name" << endl;
            }
            else
            {
                system("cls");
                display_menu();
                cout << "\"" << fname << "\" | Search results" << endl;
                cout << "-------------------------------------" << endl;
                cout << poss.size() << " results were found with this first name: " << endl;
                for (int i=0; i<poss.size(); i++)
                {
                    display_student(poss[i]);
                }
                cout << "Press Enter to continue...";
                cin.get();
                goto search_student;

            }
        }
        else if(choice == 3)
        {
            string secname;
            cout << "Enter the second name to be searched: ";
            cin.ignore();
            getline(cin, secname);
            vector<int> poss = search_students(2, secname);
            if (poss.size() == 0)
            {
                cout << "No student found with this second name" << endl;
            }
            else
            {
                system("cls");
                display_menu();
                cout << "\"" << secname << "\" | Search ressults" << endl;
                cout << "-------------------------------------" << endl;
                cout << poss.size() << " results were found with this second name: " << endl;
                for (int i=0; i<poss.size(); i++)
                {
                    display_student(poss[i]);
                }
                cout << "Press Enter to continue...";
                cin.get();
                goto search_student;
            }
        }
        else if (choice == 8)
        {
            system("cls");
            goto home;
        }
        else if (choice == 9)
        {
            system("cls");
            goto home;
        }
        else if(choice == 0)
        {
            exit(0);
        }
        student_management:
        cout << "Student Management" << endl;
        cout << "---------------------------" << endl << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Modify student information" << endl;
        cout << "2. Manage hours of absences" << endl;
        cout << "3. Manage conduct" << endl;
        cout << "4. Delete student" << endl;
        cout << "5. Display information" << endl;
        cout << "       Choice: ";
        control_choice(choice, 5, 1);
        if (choice == 1)    //Modify student
        {
            system("cls");
            display_menu();
            cout << "MODIFY STUDENT" << endl;
            cout << "--------------------" << endl;
            cout << "What do you want to modify about this student?" << endl;
            std::cout << "1. First Name(s) ";
            std::cout << std::endl << "2. Second Name(s) ";
            std::cout << std::endl << "3. Matricule ";
            std::cout << std::endl << "4. Birthdate ";
            std::cout << std::endl << "5. Sex ";
            std::cout << std::endl << "6. Level " << endl;
            std::cout << std::endl << "7. Class " << endl;
            std::cout << std::endl << "8. Option " << endl;
            control_choice(choice, 8, 2);
            if (choice == 1)
            {
                string new_name;
                cout << "Enter the new first name: ";
                cin.ignore();
                getline(cin, new_name);
                update_file("files/students.stu", pos, new_name);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 2)
            {
                string new_name;
                cout << "Enter the new second name: ";
                cin.ignore();
                getline(cin, new_name);
                update_file("files/students.stu", pos+1, new_name);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 3)
            {
                string new_string;
                cout << "Enter the new matricule: ";
                cin.ignore();
                getline(cin, new_string);
                update_file("files/students.stu", pos+2, new_string);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 4)
            {
                date birthdate;
                string new_string;
                cout << "Enter the new day of birth: ";
                control_choice(birthdate.day, 31, 2);
                cout << "Enter the new month of birth: ";
                control_choice(birthdate.month, 12, 2);
                cout << "Enter the new year of birth: ";
                control_choice(birthdate.year, 31, 2);
                update_file("files/students.stu", pos+3, new_string);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 5)
            {
                string new_sex;
                cout << "Enter the new sex: ";
                new_sex = getch();
                update_file("files/students.stu", pos+4, new_sex);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 6)
            {
                string new_level;
                cout << "Enter the new second name: ";
                getline(cin, new_level);
                update_file("files/students.stu", pos+5, new_level);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 7)   //modify class
            {
                string new_class;
                cout << "Enter the new class: ";
                display_options();
                control_choice(choice, 2, 1);
                if (choice == 1)
                {
                    system("cls");
                    display_menu();
                    display_GL();
                }
                update_file("files/students.stu", pos+6, new_class);
                cout << "Update Successful" << endl;
                goto student_management;
            }
            else if (choice == 9)
            {
                system("cls");
                goto home;
            }
            else if(choice == 0)
            {
                exit(0);
            }
        }
        else if(choice == 2)   //manage hours of absences
        {
            system("cls");
            display_menu();
            cout << "Hour of Absences Management" << endl;
            cout << "-------------------------------------" << endl << endl;
            cout << "\tStudent info:" << endl;
            display_student(pos);
            cout << endl << "Choose an option" << endl;
            cout << endl << "1. Add number of hours" << endl;
            cout << endl << "2. Reduce number of hours" << endl;
            cout << endl << "\tYour choice: ";
            control_choice(choice, 2, 1);
            if (choice == 1)
            {
                int hours, new_hours;
                cout << "Enter the number of hours to be added: ";
                control_choice(hours, 50, 2);
                new_hours = get_int("files/students.stu", pos+7);
                cout << "Got Hours: " << new_hours << endl;
                cout << "Pos: " << pos << endl;
                update_file("files/students.stu", pos+7, (hours+new_hours)+"");
            }
        }
        else if (choice == 4)  //delete student
        {
            for(int i=0; i<7; i++)
            {
                delete_line("files/students.stu", pos+i);
                cout << "Line " << pos+1 << " deleted" << endl;
                cin.get();
            }
            cout << "Student deleted" << endl;
            cout << "Press Enter to continue ...";
            cin.get();
            goto search_student;
        }
        else if (choice == 5)  //display info
        {
            display_student(pos);
            cout << endl;
            cout << "Press Enter to continue ...";
            cin.get();
            goto search_student;
        }
        else if (choice == 8)
        {
            system("cls");
            goto search_student;
        }
        else if (choice == 9)
        {
            system("cls");
            goto home;
        }
        else if(choice == 0)
        {
            exit(0);
        }
    }
    else if (choice == 8)
    {
        system("cls");
        goto home;
    }
    else if (choice == 9)
    {
        system("cls");
        goto home;
    }
    else if(choice == 0)
    {
        exit(0);
    }

    return 0;
}
