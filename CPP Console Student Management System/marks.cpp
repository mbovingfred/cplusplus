#include "files.h"
#include "marks.h"
#include "functions.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void save_marks(string coursename, vector<int> students, string coef, string classname, int period)
{
    float mark;
    ofstream mark_file("files/marks.stu", ios::app);
    if (mark_file)
    {
        for (int i=0; i<=(students.size()-1); i++)
        {
            cout << "Mark of " << get_line("files/students.stu", students[i]) << " " << get_line("files/students.stu", students[i]) << ": ";
            while ((!(cin >> mark)) && mark >=0)
            {
                "Wrong Entry. The mark must be a none-negative integer. Try again:";
                cin.clear();
                cin.ignore();
            }
            int mark_id;
            mark_id = (get_nber_lines("files/marks.stu")/6)+1;
            mark_file << mark_id << endl;
            mark_file << get_line("files/students.stu", students[i])+" "+get_line("files/students.stu", students[i]+1) << endl;
            mark_file << get_line("files/students.stu", students[i]+2) << endl;
            mark_file << coursename << endl;
            mark_file << coef << endl;
            mark_file << mark << endl;
            mark_file << classname << endl;
            switch(period)
            {
                case 1:
                    mark_file << "CA1" << endl;
                    break;
                case 2:
                    mark_file << "CA2" << endl;
                    break;
                case 3:
                    mark_file << "Semester 1" << endl;
                    break;
                case 4:
                    mark_file << "Semester 2" << endl;
                    break;
            }
        }
        cout << "Finished !" << endl;
        mark_file.close();
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
}

void display_marks(string classname)
{
    int nber_lines = get_nber_lines("files/marks.stu");
    cout << "   MARKS OF CLASS " << classname << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "   +------+--------------------+---------------+-------------+" << endl;
    cout << "   |  No  |      MATRICULE     |       NAME    |    MARK     |" << endl;
    cout << "   +------+--------------------+---------------+-------------+" << endl;
    int i=0, no=0, class_line;
    string data, matricule, name, mark;
    while (i<=nber_lines)
    {
        class_line = 7+(i*8);
        data = get_line("files/marks.stu", class_line);
        i++;
        if (data == classname)
        {
            no++;
            matricule = get_line("files/marks.stu", class_line-4);
            name = get_line("files/marks.stu", class_line-5);
            mark = get_line("files/marks.stu", class_line-1);
            if (no<10)
            {
                cout << "   |  " << no << "   |       " << matricule << "       | " << name.substr(0, 13) <<"  |    " << mark << "    |" << endl;
                cout << "   +------+--------------------+---------------+-------------+" << endl;
            }
            else
            {
                cout << "   |  " << no << "    |       " << matricule << "       | " << name.substr(0, 13) <<"  |    " << mark << "    |" << endl;
                cout << "   +------+--------------------+---------------+-------------+" << endl;
            }
        }
    }
    cout << "End!" << endl;
    cin.get();
}
