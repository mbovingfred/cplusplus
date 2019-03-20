#ifndef MARKS_H_INCLUDED
#define MARKS_H_INCLUDED

#include <string>
#include <vector>

void save_marks(std::string coursename, std::vector<int> students, std::string coef, std::string classname, int period);
void display_marks(std::string classname);
#endif // MARKS_H_INCLUDED
