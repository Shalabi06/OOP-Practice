#include <iostream>
#include <cstring>
using namespace std;

class Shape{
char color[10];
public:
Shape(char *c){
strcpy(color,c);
}
virtual double sumarea(){
return 0;

}

};
class Circle:public Shape{
double radius;
public:
Circle(char *c,double r ):Shape(c){
radius=r;
}
void setradius(double r ){
  radius=r;
}
double getradius(){
return radius;
}
double sumarea(){
return (radius *radius *3.14);

}

};
class Rectangle:public Shape{
double length;
double width;
public:
Rectangle(char *c,double l,double w):Shape(c){
length=l;width=w;
}
void setlength(double l){
  length=l;
}
double getlength(){
return length;

}
void setwidth(double w){
width=w;
}
double getwidth(){

  return width;
}
double sumarea(){
  return length * width;
}

};
double sumareas(Shape *shapes[],int size){
double sum=0;
for(int i =0;i<size;i++)
{
sum+=shapes[i]->sumarea();
}
return sum;
}






