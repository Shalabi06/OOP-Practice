#include <iostream>
#include <string>
#include<limit>
using namespace std;
class Student{
string First_name;
string Last_name;
double GPA;
int sno;
public:
Student(){
GPA=0;
sno=0;
First_name="";
Last_name="";
}
Student(string first ,string last ,double gpa ,int sno){
GPA=gpa;
this->sno=sno;
First_name=first;
Last_name=last;
}
void setGPA(int val){
 GPA=val;
}
void setFirst_Name(string  first){
First_name=first;
}
void setLast_Name(string last){
Last_name=last;
}
void setSNO(int val){
sno=val;
}
double getGPA(){
 return GPA;
}
int getSNO(){
 return sno;
}

    void displayINFO()  {
        cout << "Student First name:\t" << First_name << endl;
        cout << "Student Last name:\t" << Last_name << endl;
        cout << "=======================================================" << endl;
        cout << "Student Full name:\t" << First_name << " " << Last_name << endl;
        cout << "Student number:\t\t" << sno << endl;
        cout << "Student GPA:\t\t" << GPA << endl;
    }






};
class Department{
int number;
string deptname;
Student ** array;
public:
Department(string dname,int n ){
number=n;
deptname=dname;
array=new Student*[n];
string firstname;
string lastname;
double gpa;
int sno;
 cin.ignore();
for(int i =0;i<number;i++){
cout<<"enter first name \n";
getline(cin,firstname);
cout<<"enter last name \n";
getline(cin,lastname);
cout<<"enter student GPA \n";
cin>>gpa;
cout<<"enter student  number \n";
cin>>sno;
array[i]=new Student(firstname,lastname,gpa,sno);
}
}
void setDEPTNAME(string dname){
 deptname=dname;
}
string getDEPTNAME(){
return deptname;
}
double getAverageGPA(){
double total=0;
for(int i=0;i<number;i++)
total+=array[i]->getGPA();
return total/number;
}

    ~Department() {
        for (int i = 0; i < number; i++) {
            delete array[i];
        }
        delete[] array;
    }

    void displayStudents() {
        cout << "\nDepartment: " << deptname << "\n";
        cout << "====================================\n";
        for (int i = 0; i < number; i++) {
            cout << "Student " << (i + 1) << ":\n";
            array[i]->displayINFO();
            cout << "-----------------------------------\n";
        }
    }
};



int main() {
     Department dept("CSE", 2);
    dept.displayStudents();
    cout << "Average GPA: " << dept.getAverageGPA() << endl;

    return 0;
}



