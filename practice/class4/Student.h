#ifndef Student_h
#define Student_h

class Student{
public:
    Student();
    Student(const char *name, const char *surname);
    void Print();

    friend class StudentsList;
private:
    int _id;
    const char *_name;
    const char *_surname;
    Student *_next;
};

#endif