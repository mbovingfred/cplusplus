#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED

#include "structs"
#include <vector>

void get_student(student &new_student);
void save_student(student stu);
void regist();
void display_student(int student_pos);
int search_student(int filter, std::string value);
std::vector<int> search_students(int filter, std::string value);
int search_student();


#endif // STUDENTS_H_INCLUDED
