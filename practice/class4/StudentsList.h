#ifndef StudentsList_h
#define StudentsList_h
#include "Student.h"

class StudentsList{
public:
    StudentsList(const char *info);
    StudentsList();
    ~StudentsList();
    void PrintInfo();
    void AddStudent( Student *student);
    void PrintList();
   // void AddStudent(const Student *student);
private:
    Student *lista;
    Student *first;
    static int _num;
    const char *_info;
};
#endif