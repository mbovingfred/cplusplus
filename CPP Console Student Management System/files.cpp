#include <iostream>
#include "files.h"
#include <fstream>
#include "functions.h"
#include <vector>

using namespace std;

int update_file(string filename, int line, string new_string)
{
    ifstream file(filename.c_str());
    vector<string> temp;
    if (file)
    {
        int nber_lines = get_nber_lines(filename);
        string data;
        for (int i=1; i<=nber_lines; i++)
        {
            getline(file, data);
            if (i != line)
            {
                temp.push_back(data);
            }
            else
            {
                cout << "Deleting..." << endl;
                temp.push_back(new_string);
            }
        }
        file.close();
        ofstream file2(filename.c_str());
        for (int i=0; i<temp.size(); i++)
        {
            file2 << temp[i] << endl;
        }
        cout << "finished" << endl;
        return 0;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
        return 1;
    }
}

int delete_line(string filename, int line)
{
    ifstream file(filename.c_str());
    vector<string> temp;
    if (file)
    {
        int nber_lines = get_nber_lines(filename);
        string data;
        for (int i=1; i<=nber_lines; i++)
        {
            getline(file, data);
            if (i != line)
            {
                temp.push_back(data);
            }
            else
            {
                cout << "Deleting..." << endl;
            }
        }
        file.close();
        ofstream file2(filename.c_str());
        for (int i=0; i<temp.size(); i++)
        {
            file2 << temp[i] << endl;
        }
        cout << "finished" << endl;
        return 0;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
        return 1;
    }
}

int get_int(string filename, int line)
{
    ifstream file(filename.c_str(), std::ios::in);
    string temp_string;
    int temp_int;
    if(file)
    {
        for (int i=1; i<line; i++)
        {
            getline(file, temp_string);
        }
        file >> temp_int;
        return temp_int;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
        return -1;
    }
}
string get_line(string filename, int line)
{
    ifstream file(filename.c_str(), std::ios::in);
    string temp_string;
    if(file)
    {
        for (int i=1; i<line; i++)
        {
            getline(file, temp_string);
        }
        getline(file, temp_string);
        return temp_string;
    }
    else
    {
        cout << "ERROR OPENING FILE" << endl;
        return "-1";
    }
}

int search_line(string filename, string key, int filter, int interval)
{
    ifstream file(filename.c_str(), std::ios::in);
    int file_size = get_nber_lines(filename.c_str());
    if(file)
    {
        string got_value;
        for (int i=1; i<=filter; i++)
        {
            getline(file, got_value);
        }
        int j = filter;
        while(j<file_size && (got_value != key))
        {
            for (int k=1; k<=interval; k++)
            {
                getline(file, got_value);
                j++;
            }
        }
        if (got_value == key)
        {
            return j;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
}
