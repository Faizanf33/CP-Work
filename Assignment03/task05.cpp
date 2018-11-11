/* Question 5)
(Complex Class) Create a class called Complex for performing arithmetic with
complex numbers. Write a program to test your class. Complex numbers have
the form realPart + imaginaryPart * i where i is Use double variables to
represent the private data of the class. Provide a constructor that enables
an object of this class to be initialized when it’s declared. The constructor
should contain default values in case no initializers are provided. Provide
public member functions that perform the following tasks:
a) Adding two Complex numbers:
  The real parts are added together and the imaginary parts are added together.
b) Subtracting two Complex numbers:
  The real part of the right operand is subtracted from the real part of
  the left operand, and the imaginary part of the right operand is subtracted
  from the imaginary part of the left operand.
c) Printing Complex numbers in the form (a, b), where a is the real part and
  b is the imaginary part. 
*/
# include<iostream>
using namespace std;

class Complex {
  private:
    double realPart;
    double imaginaryPart;

  public:
    Complex(){
      realPart = 0;
      imaginaryPart = 0;
    }

    Complex(double r, double i){
      realPart = r;
      imaginaryPart = i;
    }

    double getReal(){
      return realPart;
    }

    double getImg(){
      //cout << imaginaryPart << 'i' << endl;
      return imaginaryPart;
    }

    void addComplex(Complex c1, Complex c2){
      realPart = c1.getReal() + c2.getReal();
      imaginaryPart = c1.getImg() + c2.getImg();
      return;
    }

    void subComplex(Complex c1, Complex c2){
      realPart = c1.getReal() - c2.getReal();
      imaginaryPart = c1.getImg() - c2.getImg();
      return;
    }

    void printComplex(){
      cout << "(" << realPart << "," << imaginaryPart << ")" << endl;
      return;
    }
};

int main(void){
  Complex c1(2, 3), c2(4, 5);
  c1.addComplex(c1, c2);
  c1.printComplex();
  c1.subComplex(c1, c2);
  c1.printComplex();
  return 0;
}
