#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int get_nber_lines(std::string filename);
void display_file(std::string filename);
std::string get_level(int number);
void add_level(std::string level_name);
void display_menu();
void control_choice(int &choice, int limit, int type);
int reg_marks(std::string classe, int session);
std::string get_class();
void display_SE();
void display_SR3();
void display_SR2();
void display_SR1();
void display_GL3();
void display_GL2();
void display_GL1();
void display_SR();
void display_GL();
void display_options();

#endif // FUNCTIONS_H_INCLUDED
