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
