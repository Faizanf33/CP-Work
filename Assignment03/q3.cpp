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
