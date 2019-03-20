#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <string>

int update_file(std::string filename, int line, std::string new_string);
int delete_line(std::string filename, int line);
std::string get_line(std::string filename, int line);
int get_int(std::string filename, int line);
int search_line(std::string filename, std::string key, int filter, int interval);

#endif // FILES_H_INCLUDED
