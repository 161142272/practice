#include <iostream>
#include <string>
using namespace std;

class student
{
    public:
    
    string name;
    int numberx;

    double xianshi()
    {
        cout << name << endl;
        cout << numberx;
        cout << endl;
    }

};

class student2
{
    public:

    string Mname;
    int numberx;

    void setname(string name)
    {
        Mname = name;
    }

    void setnumber(int number)
    {
        numberx = number;
    }
};

int main()
{
    student s1;
    s1.name = "小王";
    s1.numberx = 202500505005;

    
    cout << "学生的学号和姓名是:" << endl;
    s1.xianshi();

    student2 s2;
    s2.setname("张三");
    s2.setnumber(123);

}