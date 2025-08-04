#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int sno;
    string First_Name;
    string Last_Name;
    double GPA;
public:
    virtual ~Student() {}

    virtual double getGPA() =0; 
  

    Student() : sno(0), GPA(0), First_Name(""), Last_Name("") {}

    Student(string first, string last, double gpa, int sno)
        : First_Name(first), Last_Name(last), GPA(gpa), sno(sno) {}

    void setFirst_Name(string first) { First_Name = first; }
    void setLast_Name(string last) { Last_Name = last; }

    string getFirst_Name() const { return First_Name; }
    string getLast_Name() const { return Last_Name; }

    void setSNO(int val) { sno = val; }
    int getSNO() const { return sno; }

    void displayINFO() const {
        cout << "Student First name:\t" << First_Name << endl;
        cout << "Student Last name:\t" << Last_Name << endl;
        cout << "=======================================================" << endl;
        cout << "Student Full name:\t" << First_Name << " " << Last_Name << endl;
        cout << "Student number:\t\t" << sno << endl;
        cout << "Student GPA:\t\t" << GPA << endl;
    }
};

class BA : public Student {
    string major;
public:
    BA() : major("") {}

    BA(string major, string first, string last, double gpa, int sno)
        : Student(first, last, gpa, sno), major(major) {}

    double getGPA()  override { return GPA; }

    void setMajor(string major) { this->major = major; }
    string getMajor() const { return major; }
};

class MA : public Student {
    string thesisTopic;
public:
    MA() : thesisTopic("") {}

    MA(string topic, string first, string last, double gpa, int sno)
        : Student(first, last, gpa, sno), thesisTopic(topic) {}

    double getGPA()  override { return GPA; }

    void setThesisTopic(string topic) { thesisTopic = topic; }
    string getThesisTopic() const { return thesisTopic; }
};

int main() {

    Student* ptr = new BA("EE", "Ali", "Mohammad", 3.3, 1133);
    cout << "GPA of obj1: " << ptr->getGPA() << endl;

    ptr = new MA("Advanced Embedded Systems", "John", "Smith", 2.7, 22332);
    cout << "GPA of obj2: " << ptr->getGPA() << endl;

    return 0;
}  now
