/* Question 3)
Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay
a 50 cent toll. Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by, and of
the total amount of money collected. Model this tollbooth with a class
called tollBooth. The two data items are a type unsigned int to hold
the total number of cars, and a type double to hold the total amount of money
collected. A constructor initializes both of these to 0. A member function
called payingCar() increments the car total and adds 0.50 to the cash total.
Another function, called nopayCar(), increments the car total but adds nothing
to the cash total. Finally, a member function called display() displays
the two totals. Make appropriate member functions const. Include a program
to test this class. This program should allow the user to push one key
to count a paying car, and another to count a nonpaying car.
*/
# include<iostream>
using namespace std;

class tollBooth{
  private:
    unsigned int total_cars;
    double total_amount;

  public:
    tollBooth(){
      total_cars = 0;
      total_amount = 0;
    }

    void payingCar(){
      total_cars ++;
      total_amount += 0.50;
      return;
    }

    void nopayCar(){
      total_cars ++;
      return;
    }

    void display(){
      cout << "\nTotal Cars: " << total_cars <<
      '\n' << "Total Amount: $" << total_amount <<
      '\n';
      return;
    }
};


int main(void){
  tollBooth toll;

  bool exit = false;
  int choice;
  while(exit == false){
    cout << "--> TollBooth -->" <<
    '\n' << "1. Paying\n2. No paying\n0. Exit" <<
    '\n' << "Enter [0 - 2]: ";
    cin >> choice;

    if (choice == 1)
      toll.payingCar();

    else if (choice == 2)
      toll.nopayCar();

    else if (choice == 0)
      toll.display(), exit = true;

    else
      cout << "Invalid choice!" << endl;
  }

  return 0;
}
