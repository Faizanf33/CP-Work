#include <iostream>
using namespace std;

const float PI = 3.1412;

class pointType
{
  private:
    int x;
    int y;

  public:
    pointType(){
      x = 0;
      y = 0;
    }

    pointType(int a, int b){
      x = a;
      y = b;
    }

    void set_coordinates(int a, int b){
      x = a;
      y = b;
      return;
    }

    int get_x(){
      return x;
    }

    int get_y(){
      return y;
    }

    void print_coordinates(){
      cout << '(' << x << ", " << y << ')' << endl;
      return;
    }
};

class circleType: public pointType
{
  private:
    int radius;

  public:
    circleType(){
      radius = 0;
    }

    circleType(int r, int x, int y): pointType(x, y){
      radius = r;
    }

    void setRadius(int r){
        radius = r;
        return;
    }

    int getRadius(){
      return radius;
    }

    double area(){
      return PI * radius * radius;
    }

    double circumference(){
      return 2 * PI * radius;
    }

    void printCircle(){
      cout << "Radius: " << radius <<
      '\n' << "Centre: ";
      print_coordinates();

      return;
    }

};

class cylinderType: public circleType
{
  private:
    int height;

  public:
    cylinderType(){
      height = 0;
    }

    cylinderType(int h, int r, int x, int y): circleType(r, x, y){
      height = h;
    }

    void setHeight(int h){
      height = h;
      return;
    }

    int getHeight(){
      return height;
    }

    double volume(){
      return (area() * height);  // pi*r^2*h
    }

    double surfaceArea(){
      return (circumference() * height) + (2 * area()); // 2(pi*r*h + pi*r^2)
    }

    void printCylinder(){
      printCircle();
      cout << "Height: " << height << endl;

      return;
    }
};

int main(){
    cylinderType c(10, 4, 5, 10);
    c.printCylinder();
    cout << "Volume: "<< c.volume() << endl;
    cout << "Surface area: " << c.surfaceArea() << endl;

}
