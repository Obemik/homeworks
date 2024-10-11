#include <iostream>
using namespace std;

class Student
{
protected:
    string _name;
    string _university;
    int _age;
public:
    Student()
    {
        _name = "No name";
        _university = "No university";
        _age = -1;
        cout << "Student created" << endl;
    }
    Student(string name, string university, int age)
    {
        _name = name;
        _university = university;
        _age = age;
        cout << "Student created with param" << endl;
    }

    virtual void about()
    {
        cout << "Name: " << _name << endl;
        cout << "University: " << _university << endl;
        cout << "Age: " << _age << endl;
    }

    virtual ~Student()
    {
        cout << "Student destroyed" << endl;
    }
};

class Aspirant : public Student
{
private:
    string _researchTopic;
public:
    Aspirant() : Student()
    {
        cout << "Aspirant created" << endl;
    }
    Aspirant(string name, int age) : Student(name, "Taras Shevchenko National University of Kyiv.", age)
    {
        cout << "Aspirant created with param" << endl;
    }

    void about() override
    {
        cout << "Name: " << _name << endl;
        cout << "University: " << _university << endl;
        cout << "Age: " << _age << endl;
        cout << "Aspirant preparing for a Test" << endl;
    }

    ~Aspirant()
    {
        cout << "Aspirant destroyed" << endl;
    }
};

void print(Student* student)
{
    student->about();
}

int main() {
    Aspirant* aspirant = new Aspirant("Alex", 25);
    print(aspirant);
    delete aspirant;
    cout << endl;

    return 0;
}