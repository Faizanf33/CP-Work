# include<iostream>
# include<string>
using namespace std;

class Vehicle
{
	private:
		int no_of_tyres;
		int no_of_seats;

	public:
		Vehicle()
		{
			no_of_tyres = 0;
			no_of_seats = 0;
		}

		Vehicle(int t, int s)
		{
			no_of_tyres = t;
			no_of_seats = s;
		}

		void setTyres(int t)
		{
			no_of_tyres = t;
			return;
		}

		int getTyres()
		{
			return no_of_tyres;
		}

		void setSeats(int s)
		{
			no_of_seats = s;
			return;
		}
		
		int getSeats()
		{
			return no_of_seats;
		}

		void printVehicle()
		{
			cout << "Number of tyres: " << no_of_tyres <<
			'\n' << "Number of seats: " << no_of_seats <<
			endl;
			
			return;
		}
};

class Car: public Vehicle
{
	private:
		string color;
	
	public:
		Car()
		{
			color = "";
		}
		
		Car(int t, int s, string c): Vehicle(t, s)
		{
			color = c;
		}
		
		void setColor(string c)
		{
			color = c;
		}
		
		string getColor()
		{
			return color;
		}
		
		void printCar()
		{
			printVehicle();
			cout << "Color: " << color
			<< endl;
			
			return;
		}
};

class Vitz: public Car
{
	private:
		string model;
		string plate_number;
		
	public:
		Vitz()
		{
			model = "";
			plate_number = "";
		}

		Vitz(int t, int s, string c, string m, string p): Car(t, s, c)
		{
			model = m;
			plate_number = p;
		}
		
		void setModel(string m)
		{
			model = m;
			return;
		}
		
		string getModel()
		{
			return model;
		}
		
		void setPlateNumber(string p)
		{
			plate_number = p;
			return;
		}
		
		void printVitz()
		{
			printCar();
			cout << "Model: " << model <<
			'\n' << "Plate number: " << plate_number 
			<< endl;
			return;
		}
};
