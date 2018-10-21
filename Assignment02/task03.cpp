/*
Q3) Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:
a. Show the customer the different breakfast items offered by the restaurant.
b. Allow the customer to select more than one item from the menu.
c. Calculate and print the bill.
*/

# include<iostream>
# include<iomanip>
# include<fstream>
# include<string>
using namespace std;

struct menuItemType{
	string item_name;
	char ingredients[3];
	int quantity, 
		time;
	double charges, 
		tax;
};

void printCheck(menuItemType menuList[], int size, int order[]){
	double amount = 0.0, tax = 0.0;

	cout << setw(18) << left << "|[:] ITEM " <<
	 setw(8) << " QUANTITY " << 
	 setw(10) << " PRICE/ITEM " << 
	 setw(8) << " INGREDIENTS	|" << endl;
	for (int i=0; i<size; i++){
		if (order[i] == 1){
			tax += menuList[i].tax;
			amount += menuList[i].charges;
			cout << "|["<< (i+1) <<"] ";
			cout << setw(15) << left << menuList[i].item_name; 
			cout << setw(6) << right << 1;
			cout << fixed << setprecision(2) << setw(9) << right << "$" <<menuList[i].charges;
			cout << setw(3) << right << menuList[i].ingredients[0] << "," <<
				setw(0) << left << menuList[i].ingredients[1] << "," <<
				setw(0) << left << menuList[i].ingredients[2];
			cout << "\t\t|" << endl;
		
		}
	}	
	cout << setw(25) << left <<"|TOTAL TAX " <<
	 setw(8) << setw(10) << fixed << right << setprecision(2) << "$" << tax << "\t\t\t|" << endl;
	cout << setw(25) << left <<"|AMOUNT DUE " <<
	 setw(8) << setw(10) << fixed << right << setprecision(2) << "$" << amount+tax << "\t\t\t|" << endl;
	
	return;
}

void showMenu(menuItemType menuList[], int size, int order[]){
	cout << setw(15) << left << "|[:] NAME OF ITEM " <<
	 setw(8) << " QUANTITY " << 
	 setw(6) << right << " TAX " << 
	 setw(12) << " WAITING TIME " << 
	 setw(10) << " CHARGES " << 
	 setw(8) << " INGREDIENTS  |" << endl;
	for (int i=0; i<size; i++){
		if (order[i] == 0){
			cout << "|["<< (i+1) <<"] ";
			cout << setw(15) << left << menuList[i].item_name; 
			cout << setw(6) << right << menuList[i].quantity;
			cout << fixed << setprecision(1) << setw(7) << right << menuList[i].tax;
			cout << setw(8) << right << menuList[i].time << " mints";
			cout << fixed << setprecision(2) << setw(6) << right << "$" <<menuList[i].charges;
			cout << setw(3) << right << menuList[i].ingredients[0] << "," <<
				setw(0) << left << menuList[i].ingredients[1] << "," <<
				setw(0) << left << menuList[i].ingredients[2];
			cout << "\t|" << endl;
		}
	}
	return;
}

bool getData(string file, menuItemType menuList[], int size){
	ifstream fin(file.c_str());
	if (fin){
		for (int i=0; i<size; i++){
			getline(fin, menuList[i].item_name);
			fin >> menuList[i].quantity;
			fin >> menuList[i].tax;
			fin >> menuList[i].time;
			fin >> menuList[i].charges;
			fin >> menuList[i].ingredients[0] >> 
				menuList[i].ingredients[1] >> 
				menuList[i].ingredients[2];
			fin.ignore('\n', 10);
		}
		fin.close();
		return true;
	}
	else
		return false;
}

int main(void){
	string file = "data3.txt";
	int size = 8;
	menuItemType menuList[size];
	if (getData(file, menuList, size)){
		int choice, order[size] = {0};
		cout << "Welcome to Johnny's Restaurant!\nWhat would you like to order?\n" << endl;
		while (choice != 0){
			showMenu(menuList, size, order);
			cout << "\nSelect choice [1 - 8] / finalize order [0]: ";
			cin >> choice;
			if (order[choice-1] == 1){
				cout << "Already selected!" << endl;
			}
			else if (choice >= 1 && choice <= 8){
				order[choice-1] = 1;
			}
			else if (choice > 8){
				cout << "Invalid choice!" << endl;
			}
		}
		cout << "\n|\tBILL DETAIL\tJOHNNY'S RESTAURANT\t\t|" << endl;
		printCheck(menuList, size, order);
		cout << "|\n|We hope you enjoyed our services!\t\t\t|" << endl;
	}
	return 0;
}
