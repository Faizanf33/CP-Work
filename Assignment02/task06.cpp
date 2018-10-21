/*
Q6) Write a program that declares a struct to store the data of a football player (player’s name, player’s position, number of touchdowns, number of catches, number of passing yards, number of receiving yards, and the number of rushing yards). Declare an array of 10 components to store the data of 10 football players. Your program must contain a function to input data and a function to output data. Add functions to search the array to find the index of a specific player, and update the data of a player. (You may assume that input data is stored in a file.) Before the program terminates, give the user the option to save data in a file. Your program should be menu driven, giving the user various choices.
*/

# include<iostream>
# include<fstream>
# include<string>
using namespace std;

struct Player{
	string name,
		position;
		
	int touchdowns,
		catches,
		passing_yards, 
		receiving_yards,
		rushing_yards;
};

string upper(string line){
	string upperStr;
	int size = line.length();	
	for (int i=0; i<size; i++){
		if (line[i] >= char(97) && line[i] <= char(122)) 
			upperStr += char(line[i] - 32);			
		else 
			upperStr += line[i];
	}
	return upperStr;
}

bool getData(string file, Player player[], int size){
	ifstream fin(file.c_str());
	if (fin){
		for (int i=0; i<size; i++){
			fin >> player[i].name >> player[i].position >> player[i].touchdowns >> 
			player[i].catches >> player[i].passing_yards >> player[i].receiving_yards >> 
			player[i].rushing_yards;
		}
		fin.close();
		return true;
	}
	else
		return false;
}

bool outData(string file, Player player[], int size){
	ofstream fout(file.c_str());
	for (int i=0; i<size; i++){
		fout << player[i].name <<" "<< player[i].position <<" "<< player[i].touchdowns 
		<<" "<< player[i].catches <<" "<< player[i].passing_yards <<" "<< player[i].receiving_yards 
		<<" "<< player[i].rushing_yards << endl;
	}
	return true;
}

int searchData(string name, Player player[], int size){
	for (int i=0; i<size; i++){
		if (upper(name) == upper(player[i].name)) 
			return i;
	}
	return -1;
}

void showInfo(int index, Player player[]){

	cout << player[index].name << "'s record : " << endl;
	cout << "1. Position			:	" << player[index].position << endl;
	cout << "2. Number of touchdowns		:	" << player[index].touchdowns << endl;
	cout << "3. Number of catches		:	" << player[index].catches << endl;
	cout << "4. Number of passing yards	:	" << player[index].passing_yards << endl;
	cout << "5. Number of receiving yards	:	" << player[index].receiving_yards << endl;
	cout << "6. Number of rushing yards	:	" << player[index].rushing_yards << endl;
	cout << endl;
	return;
}

void updateInfo(int index, Player player[]){
	showInfo(index, player);
	int opt;
	cout << "Update (1 - 6): ";
	cin >> opt;

	if (opt < 1 || opt > 6){
		cout << "Invalid option!\n" << endl;
		return;
	}
	else 
		cout << "Update info(" << opt << "): ";
	
	if (opt == 1) 
		cin >> player[index].position;
	else if (opt == 2) 
		cin >> player[index].touchdowns;
	else if (opt == 3) 
		cin >> player[index].catches;
	else if (opt == 4) 
		cin >> player[index].passing_yards;
	else if (opt == 5) 
		cin >> player[index].receiving_yards;
	else if (opt == 6) 
		cin >> player[index].rushing_yards;
	
	cout <<"Info("<< opt << ") updated!" << endl;
	return;
}

void choices(string file, Player player[], int size){
	bool exit = false;
	char choose;
	while(exit == false){
		cout << "1. Search player\n2. Update player's info\n0. Exit\nOption (0 - 2): ";
		cin >> choose;

		if (choose == '1' || choose == '2'){
			string msg = "Enter name : ", name;
			cout << msg;
			cin >> name;
			// search data
			int index = searchData(name, player, size);
			
			if (choose == '1' && index >= 0) 
				showInfo(index, player);
			else if (choose == '2' && index >= 0) 
				updateInfo(index, player);
			else 
				cout << "Player : '" << name << "' has no record!\n" << endl;
		}	
		else 
			exit = true;
	}
	cout << "Save changings (Y/n): ";
	cin >> choose;
	if (choose == 'Y' || choose == 'y'){
		outData(file, player, size);
		cout << "Data saved to file : '" << file << "'!" << endl;
	}
	else 
		cout << "Data unsaved!" << endl;

	return;
}

int main(void){
	string file = "data6.txt";
	int size = 10;
	Player player[size];

	if (getData(file, player, size))
		choices(file, player, size); 
	else
		cout << "File : '" << file << "' not found!" << endl;
	
	return 0;
}
