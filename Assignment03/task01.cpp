/* Question 1)
Create a class Rectangle with attributes length and width, each of which
defaults to 1. Provide member functions that calculate the perimeter and
the area of the rectangle. Also, provide set and get functions for the length
and width attributes. The set functions should verify that length and width
are each floating-point numbers larger than 0.0 and less than 20.0.
*/

# include<iostream>
using namespace std;

class Rectangle{
    private:
        float length;
        float width;

    public:
        Rectangle(){
            length = 1, width = 1;
        }

        void setValue(float l, float w){
            if ((l >= 0.0 and l <= 20.0) and (w >= 0.0 and w <= 20.0))
                length = l, width = w;

            else
                cout << "Value not set!" << endl;

            return;
        }

        float getLength(){
            return length;
        }

        float getWidth(){
            return width;
        }

        double perimeter(){
            return (2 * (length + width));
        }

        double area(){
            return (length * width);
        }
};
int main(void) {
  Rectangle r1;
  r1.setValue(10.25, 19.82);
  cout << r1.getLength() << endl;
  cout << r1.perimeter() << endl;
  cout << r1.area() << endl;
  return 0;
}
