#include <iostream>
#include <string>

// practicing small example on polymorphism ,abstracted class 
class Student {
protected:
    int sno;
    std::string First_Name;
    std::string Last_Name;
    double GPA;
public:
    virtual ~Student() {}

    virtual double getGPA() const = 0; 

    Student() : sno(0), GPA(0), First_Name(""), Last_Name("") {}

    Student(std::string first, std::string last, double gpa, int sno)
        : First_Name(first), Last_Name(last), GPA(gpa), sno(sno) {}

    void setFirst_Name(std::string first) { First_Name = first; }
    void setLast_Name(std::string last) { Last_Name = last; }

    std::string getFirst_Name() const { return First_Name; }
    std::string getLast_Name() const { return Last_Name; }

    void setSNO(int val) { sno = val; }
    int getSNO() const { return sno; }

    virtual void displayINFO() const {
        std::cout << "Student First name:\t" << First_Name << "\n";
        std::cout << "Student Last name:\t" << Last_Name << "\n";
        std::cout << "=======================================================\n";
        std::cout << "Student Full name:\t" << First_Name << " " << Last_Name << "\n";
        std::cout << "Student number:\t\t" << sno << "\n";
        std::cout << "Student GPA:\t\t" << GPA << "\n";
    }
};

class BA : public Student {
    std::string major;
public:
    BA() : major("") {}

    BA(std::string major, std::string first, std::string last, double gpa, int sno)
        : Student(first, last, gpa, sno), major(major) {}

    double getGPA() const override { return GPA; }

    void setMajor(std::string major) { this->major = major; }
    std::string getMajor() const { return major; }

    void displayINFO() const override {
        Student::displayINFO();
        std::cout << "Major:\t\t" << major << "\n";
    }
};

class MA : public Student {
    std::string thesisTopic;
public:
    MA() : thesisTopic("") {}

    MA(std::string topic, std::string first, std::string last, double gpa, int sno)
        : Student(first, last, gpa, sno), thesisTopic(topic) {}

    double getGPA() const override { return GPA; }

    void setThesisTopic(std::string topic) { thesisTopic = topic; }
    std::string getThesisTopic() const { return thesisTopic; }

    void displayINFO() const override {
        Student::displayINFO();
        std::cout << "Thesis Topic:\t" << thesisTopic << "\n";
    }
};

int main() {
    std::unique_ptr<Student> ptr = std::make_unique<BA>("EE", "Ali", "Mohammad", 3.3, 1133);
    std::cout << "GPA of obj1: " << ptr->getGPA() << "\n";
    ptr->displayINFO();

    ptr = std::make_unique<MA>("Advanced Embedded Systems", "John", "Smith", 2.7, 22332);
    std::cout << "GPA of obj2: " << ptr->getGPA() << "\n";
    ptr->displayINFO();

    return 0;
}
