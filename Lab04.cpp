# include<iostream>
# include<fstream>
# include<string>
using namespace std;

struct user_info{
	string name, 
		email;
	
	int passwd; 
};


int main(){
	user_info user[5];
	
	string file;
	cout << "Enter file name : ";
	cin >> file;
	ifstream fin(file.c_str());
	
	if (fin.is_open())
		for (int i=0; i<5; i++)
			fin >> user[i].name >> user[i].email >> user[i].passwd;
	else
		cout << "file not found!" << endl;
	
	fin.close();

	string outfile;	
	cout << "Enter output file name : ";
	cin >> outfile;		
	ofstream fout(outfile.c_str(), ios::app);
	
	for (int i=0; i<5; i++)
		fout << user[i].name << " " << user[i].email << " " << "0$00###" << endl;	
	
	fout.close();
	
	return 0;		
}
