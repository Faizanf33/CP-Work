#include <iostream>
using namespace std;

class Animal{
     public:
     void print() {
         cout << "Hello";
    }
};

class Dog: public Animal{
public:
  void print() {
    cout << "Dog Class...";
  }
};

int main(int argc, char const *argv[]) {
  Dog obj;
  obj = Animal();
  obj.print();

  return 0;
}
